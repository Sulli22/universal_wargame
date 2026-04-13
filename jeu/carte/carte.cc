#include "carte.hh"
#include "casemarine.hh"
#include "caseterrestre.hh"
#include "lecteur.hh"
#include "createurcases.hh"
#include "createurunites.hh"
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

Case* Carte::accesCase(const Position &pos)
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

std::map<Case *, int> Carte::getCasesAtteignables(Case *depart, Unite *unite) const
{
    std::queue<Case *> file;
    std::map<Case *, int> coutJusqua;
    file.push(depart);
    coutJusqua[depart] = 0;

    while (!file.empty()) {
        Case* courant = file.front();
        file.pop();

        for (Case* caseVoisine : getVoisines(*courant)) {
            int coutMvt = caseVoisine->coutDeplacement(unite);
            if (coutMvt == std::numeric_limits<int>::max()) continue;

            int nouveauCout = coutJusqua[courant] + coutMvt;

            // trop loin
            if (nouveauCout > unite->getCapaciteDeplacement()) continue;

            // zoc ennemie atteinte
            if (caseDansZocEnnemie(caseVoisine, unite)) {
                coutJusqua[caseVoisine] = nouveauCout;
                continue;
            }

            // si jamais vu ou meilleur chemin
            if (!coutJusqua.count(caseVoisine) ||
                nouveauCout < coutJusqua[caseVoisine]) {
                coutJusqua[caseVoisine] = nouveauCout;
                file.push(caseVoisine);
            }
        }
    }
    return coutJusqua;
}

bool Carte::caseDansZocEnnemie(Case *caseCible, Unite *uniteEnDeplacement) const
{
    for (const auto &voisine : getVoisines(*caseCible)) {
        if (caseCible->getFaction() != Faction::neutre &&
            uniteEnDeplacement->getFaction() != voisine->getFaction())
            return true;
    }
    return false;
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

void Carte::afficherDetails(std::ostream &os)
{
    for (std::size_t q = 0; q < _largeur; ++q) {
        for (std::size_t r = 0; r < _hauteur; ++r) {
            auto c = accesCase({(int)q, (int)r});

            c->afficherDetails(os);

            auto voisines = getVoisines(*c);
            os << "Voisines = ";
            for (const auto &v : voisines) {
                v->sortieFlux(os);
                os << " ";
            }
            os << std::endl;
        }
    }
}
