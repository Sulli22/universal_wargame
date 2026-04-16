#include "carte.hh"
#include "casemarine.hh"
#include "caseterrestre.hh"
#include "lecteur.hh"
#include "createurcases.hh"
#include "createurunites.hh"
#include <algorithm>
#include <sstream>
#include <queue>
#include <limits>

const std::vector<Position> Carte::_DIRECTIONS = {
            {0, -1},
    {-1, 0},       {1, 0},
    {-1, 1},       {1,  1},
            {0,  1},
};

Carte::Carte(unsigned int idGuerre)
{
    auto prefixe = "data/guerre" + std::to_string(idGuerre) + "/";
    auto nomFichierCases = prefixe + "cases.txt";
    auto nomFichierUnites = prefixe + "unites.txt";

    // Cases
    auto lignesCases = Lecteur::lireLignes(nomFichierCases);
    std::size_t r = 0;
    std::size_t largeur_attendue = 0;

    for (const auto& ligne : lignesCases) {
        std::stringstream ss(ligne);
        std::string token;
        std::vector<std::unique_ptr<Case>> cases;
        std::size_t q = 0;

        while (ss >> token) {
            if (token.size() < 2)
                throw std::runtime_error("Erreur : token invalide.");

            char type = token[0];
            int nombre = std::stoi(token.substr(1));

            if (nombre <= 0)
                throw std::runtime_error("Erreur : nombre invalide.");

            for (int i = 0; i < nombre; ++i) {
                cases.push_back(CreateurCases::creer(type, Position(q, r)));
                q++;
            }
        }

        // vérification de la largeur
        if (r == 0)
            largeur_attendue = q; // première ligne = référence
        else if (q != largeur_attendue)
            throw std::runtime_error("Erreur : lignes de tailles differentes.");

        _contenu.push_back(std::move(cases));
        r++;
    }

    _largeur = largeur_attendue;
    _hauteur = r;

    // Unites
    auto lignesUnites = Lecteur::lireLignes(nomFichierUnites);

    for (const auto& ligne : lignesUnites) {
        std::stringstream ss(ligne);
        int q;
        int r;
        char type;
        char faction;

        while (ss >> q && ss >> r && ss >> type && ss >> faction) {
            Case *c = accesCase({q, r});
            if (!c)
                throw std::runtime_error("Erreur : Case invalide "
                                         + std::to_string(q) + ","
                                         + std::to_string(r));

            if (type == 'C' || type == 'B')
                c->setUniteAerienne(CreateurUnites::creerAerienne(type, faction));

            else {
                if (CaseMarine *cm = dynamic_cast<CaseMarine *>(c))
                    cm->setUniteBasse(CreateurUnites::creerMarine(type, faction));
                else if (CaseTerrestre *ct = dynamic_cast<CaseTerrestre *>(c))
                    ct->ajouterUniteTerrestre(CreateurUnites::creerTerrestre(type, faction));
                else
                    throw std::runtime_error("Erreur : type de case inconnu");
            }
        }
    }
}

std::size_t Carte::getLargeur() const
{
    return _largeur;
}

std::size_t Carte::getHauteur() const
{
    return _hauteur;
}

const std::vector<std::vector<std::unique_ptr<Case>>> &Carte::getContenu() const
{
    return _contenu;
}

Case* Carte::accesCase(const Position &pos) const
{
    return _contenu[pos.getR()][pos.getQ()].get();
}

bool Carte::positionValide(const Position &pos) const
{
    int q = pos.getQ();
    int r = pos.getR();

    // Vérifie que q et r sont non négatifs et dans les limites
    return (q >= 0 && q < static_cast<int>(_largeur))
        && (r >= 0 && r < static_cast<int>(_hauteur));
}

std::vector<Case *> Carte::getVoisines(const Case &c) const
{
    std::vector<Case *> voisins;

    auto pos = c.getPos();

    for (const auto &d : _DIRECTIONS) {
        auto voisin = pos + d;
        if (positionValide(voisin))
            voisins.push_back(_contenu[voisin.getR()][voisin.getQ()].get());
    }

    return voisins;
}

std::map<Case *, usint> Carte::getCasesAtteignables(Case *depart, Unite *uniteEnDeplacement) const
{
    std::queue<Case *> file;
    std::map<Case *, usint> coutJusqua;
    file.push(depart);
    coutJusqua[depart] = 0;

    while (!file.empty()) {
        Case* courant = file.front();
        file.pop();

        for (Case* caseVoisine : getVoisines(*courant)) {
            usint coutMvt = caseVoisine->coutDeplacement(uniteEnDeplacement);
            if (coutMvt == std::numeric_limits<usint>::max())
                continue;

            usint nouveauCout = coutJusqua[courant] + coutMvt;

            // trop loin
            if (nouveauCout > uniteEnDeplacement->getCapaciteDeplacement())
                continue;

            // zoc ennemie atteinte
            if (caseDansZocEnnemie(caseVoisine, *uniteEnDeplacement)) {
                coutJusqua[caseVoisine] = nouveauCout;
                continue;
            }

            // si jamais vu ou meilleur chemin
            if (!coutJusqua.count(caseVoisine) || nouveauCout < coutJusqua[caseVoisine]) {
                coutJusqua[caseVoisine] = nouveauCout;
                file.push(caseVoisine);
            }
        }
    }
    return coutJusqua;
}

// algo type A*
std::vector<Case *> Carte::getChemin(Case *depart, Case *arrivee, Unite *uniteEnDeplacement) const
{
    using PQElement = std::pair<usint, Case *>;
    std::priority_queue<PQElement, std::vector<PQElement>, std::greater<>> aExplorer;
    aExplorer.push({0, depart});

    std::map<Case *, Case *> vientDe;
    std::map<Case *, usint> coutJusqua;
    vientDe[depart] = depart;
    coutJusqua[depart] = 0;

    while (!aExplorer.empty()) {
        Case * courante = aExplorer.top().second;
        aExplorer.pop();

        if (courante == arrivee) break;

        for (Case *suiv : getVoisines(*courante)) {
            usint coutMvt = suiv->coutDeplacement(uniteEnDeplacement);
            if (coutMvt == std::numeric_limits<usint>::max())
                continue;

            int nvCout = coutJusqua[courante] + coutMvt;
            if (!coutJusqua.count(suiv) || nvCout < coutJusqua[suiv]) {
                coutJusqua[suiv] = nvCout;
                usint priorite = nvCout + distance(*suiv, *arrivee);
                aExplorer.push({priorite, suiv});
                vientDe[suiv] = courante;
            }
        }
    }
    if (!vientDe.count(arrivee)) return {}; // pas de chemin
    return reconstruitChemin(vientDe, depart, arrivee); // reconstruction du chemin
}

bool Carte::caseDansZocEnnemie(Case *caseCible, const Unite &uniteEnDeplacement) const
{
    auto zoc = getZOC();

    auto it = zoc.find(caseCible);
    if (it == zoc.end())
        return false;

    for (Faction f : it->second) {
        if (f != Faction::neutre && f != uniteEnDeplacement.getFaction())
            return true;
    }

    return false;
}

std::map<Case *, std::set<Faction>> Carte::getZOC() const
{
    std::map<Case *, std::set<Faction>> zoc;

    for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            Case *c = accesCase({(int)q, (int)r});

            for (Case *v : getVoisines(*c))
                zoc[v].insert(c->getFaction());
        }
    }

    return zoc;
}

void Carte::effectuerActionsCases() const
{
    for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            Case *c = accesCase({(int)q, (int)r});

            // seules les cases terrestres ont des actions
            auto caseTerrestre = dynamic_cast<CaseTerrestre *>(c);
            if (caseTerrestre)
                caseTerrestre->effectuerActionConstruction();
        }
    }
}

usint Carte::nbUnites(Faction faction) const
{
    usint sum = 0;
    for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            Case *c = accesCase({(int)q, (int)r});

            if (c->getFaction() == faction)
                sum += c->nbUnites();
        }
    }

    return sum;
}

void Carte::soriteFlux(std::ostream &os) const
{
    os << "[largeur=" << _largeur << ", hauteur=" << _hauteur << "]" << std::endl;
    for (std::size_t r = 0; r < _hauteur; ++r) {
        // ligne des colonnes impaires
        for (std::size_t q = 1; q < _largeur; q += 2) {
            os << "\t";
            _contenu[r][q]->sortieFlux(os);
            os << "\t";
        }
        os << std::endl;

        // ligne des colonnes paires
        for (std::size_t q = 0; q < _largeur; q += 2) {
            _contenu[r][q]->sortieFlux(os);
            os << "\t\t";
        }
        os << std::endl;
    }
}

void Carte::afficherDetails(std::ostream &os) const
{
    for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            auto c = accesCase({(int)q, (int)r});

            c->afficherDetails(os);

            auto voisines = getVoisines(*c);
            os << "Voisines = ";
            for (const auto &v : voisines) {
                v->sortieFlux(os);
                os << " ";
            }
            os << std::endl;

            auto unites = c->getUnites();
            for (const auto &u : unites) {
                os << "Atteignable par " << u->getNom() << " = ";
                auto casesAtt = getCasesAtteignables(c, u);
                for (const auto &ca : casesAtt) {
                    ca.first->sortieFlux(os);
                    os <<  "(" << ca.second << ") ";
                }
                os << std::endl;
            }
        }
    }
}

usint Carte::distance(const Case &a, const Case &b)
{
    Position posA = a.getPos();
    Position posB = b.getPos();

    int aq = posA.getQ();
    int ar = posA.getR();
    int bq = posB.getQ();
    int br = posB.getR();

    int dq = aq - bq;
    int dr = ar - br;
    int ds = (aq + ar) - (bq + br);

    return (std::abs(dq) + std::abs(dr) + std::abs(ds)) / 2;
}

std::vector<Case *> Carte::reconstruitChemin(const std::map<Case *, Case *> &vientDe,
                                             Case *depart, Case *arrivee)
{
    std::vector<Case *> chemin;

    Case *courant = arrivee;

    // Remonte de l'arrivee vers le depart
    while (!(courant == depart)) {
        chemin.push_back(courant);

        auto it = vientDe.find(courant);
        if (it == vientDe.end()) // sécurité : chemin cassé
            return {};
        courant = it->second;
    }

    chemin.push_back(depart); // ajouter le départ

    // inverser pour avoir depart vers arrivee
    std::reverse(chemin.begin(), chemin.end());

    return chemin;
}
