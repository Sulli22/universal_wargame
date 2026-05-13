#include "carte.hh"

#include "casemarine.hh"
#include "caseterrestre.hh"
#include "lecteur.hh"
#include "createurcases.hh"
#include "createurunites.hh"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <limits>

// colonnes paires
const std::vector<Position> Carte::_DIRECTIONS_IMPAIRES = {
    { 0, -1},  // bas
    { 0,  1},  // haut
    {-1,  0},  // gauche milieu
    { 1,  0},  // droite milieu
    {-1, -1},  // gauche bas
    { 1, -1},  // droite bas
};

// colonnes impaires
const std::vector<Position> Carte::_DIRECTIONS_PAIRES = {
    { 0, -1},  // bas
    { 0,  1},  // haut
    {-1,  0},  // gauche milieu
    { 1,  0},  // droite milieu
    {-1,  1},  // gauche haut
    { 1,  1},  // droite haut
};

Carte::Carte(unsigned int idGuerre)
{
    auto prefixe            = "data/guerre" + std::to_string(idGuerre) + "/";
    auto nomFichierCases    = prefixe + "cases.txt";
    auto nomFichierUnites   = prefixe + "unites.txt";

    // Cases
    auto lignesCases = Lecteur::lireLignes(nomFichierCases);
    std::size_t r                   = 0;
    std::size_t largeur_attendue    = 0;

    for (const auto& ligne : lignesCases) {
        std::stringstream                   ss(ligne);
        std::string                         token;
        std::vector<std::unique_ptr<Case>>  cases;
        std::size_t                         q = 0;

        while (ss >> token) {
            if (token.size() < 2)
                throw std::runtime_error("Erreur : token invalide.");

            char    type    = token[0];
            int     nombre  = std::stoi(token.substr(1));

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
        int q, r;
        char type, faction;

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

bool Carte::positionValide(const Position &pos) const
{
    int q = pos.getQ();
    int r = pos.getR();

    // vérifie que q et r sont non négatifs et dans les limites
    return (q >= 0 && q < static_cast<int>(_largeur))
           && (r >= 0 && r < static_cast<int>(_hauteur));
}

Case* Carte::accesCase(const Position &pos) const
{
    if (!positionValide(pos))
        throw std::invalid_argument("Erreur : la position n'est pas valide" + std::to_string(pos.getQ()) + std::to_string(pos.getR()));

    return _contenu[pos.getR()][pos.getQ()].get();
}

std::vector<Case *> Carte::getVoisinesConstructibles(const Case &c, const Genie &genie) const
{
    std::vector<Case *> res;

    auto voisines = getVoisines(c);
    for(const auto &v : voisines) {
        if (v->estConstructible(genie))
            res.push_back(v);
    }

    return res;
}

std::map<Case *, distance> Carte::getCasesAtteignables(Case *depart, Unite *uniteEnDeplacement) const
{
    auto zoc = getZOC();
    bool departEnZoc = caseDansZocEnnemie(depart, *uniteEnDeplacement, zoc);

    std::queue<Case *> file;
    std::map<Case *, distance> coutJusqua;
    file.push(depart);
    coutJusqua[depart] = 0;

    while (!file.empty()) {
        Case *courante = file.front();
        file.pop();

        // si depart en ZOC, on ne propage pas au dela du premier pas
        if (departEnZoc && courante != depart)
            continue;

        for (Case *caseVoisine : getVoisines(*courante)) {
            Stat coutMvt = caseVoisine->coutDeplacement(uniteEnDeplacement);

            // infranchissable
            if (coutMvt == std::numeric_limits<Stat>::max()) continue;

            Stat nouveauCout = coutJusqua[courante] + coutMvt;

            // trop loin
            if (nouveauCout > uniteEnDeplacement->getCapaciteDeplacement()) continue;

            bool voisineEnZoc = caseDansZocEnnemie(caseVoisine, *uniteEnDeplacement, zoc);

            // si depart en ZOC, on interdit d'aller vers une autre ZOC
            if (departEnZoc && voisineEnZoc) continue;

            if (!coutJusqua.count(caseVoisine) || nouveauCout < coutJusqua[caseVoisine]) {
                coutJusqua[caseVoisine] = nouveauCout;
                if (!voisineEnZoc) // ZOC stoppe la propagation
                    file.push(caseVoisine);
            }
        }
    }

    coutJusqua.erase(depart);
    return coutJusqua;
}
std::vector<Case *> Carte::getCasesAttaquables(Case *depart, Unite *uniteAttaquante) const
{
    std::vector<Case *> casesAttaquables;
    Stat portee = uniteAttaquante->getDistanceAttaque();
    std::queue<std::pair<Case*, Stat>> file;
    std::set<Case *> visitees;

    file.push({depart, 0});
    visitees.insert(depart);

    while (!file.empty()) {
        auto [courante, distance] = file.front();
        file.pop();

        if (distance > 0
            && courante->nbUnites() > 0
            && courante->getFaction() != uniteAttaquante->getFaction()
            && courante->nbUnites() <= uniteAttaquante->getNbMunitions())
            casesAttaquables.push_back(courante);

        // stop si on atteint la portée max
        if (distance > portee)
            continue;

        for (Case* voisine : getVoisines(*courante)) {
            if (!visitees.count(voisine)) {
                visitees.insert(voisine);
                file.push({voisine, distance + 1});
            }
        }
    }

    return casesAttaquables;
}

std::vector<Case *> Carte::getChemin(Case *depart, Case *arrivee, Unite *uniteEnDeplacement) const
{
    auto zoc = getZOC(); // precalcul zoc

    using PQElement = std::pair<Stat, Case *>;
    std::priority_queue<PQElement, std::vector<PQElement>, std::greater<>> aExplorer;
    aExplorer.push({0, depart});
    std::map<Case *, Case *> vientDe;
    std::map<Case *, Stat> coutJusqua;
    vientDe[depart] = depart;
    coutJusqua[depart] = 0;

    while (!aExplorer.empty()) {
        Case *courante = aExplorer.top().second;
        aExplorer.pop();

        if (courante == arrivee) break;

        for (Case *suiv : getVoisines(*courante)) {
            Stat coutMvt = suiv->coutDeplacement(uniteEnDeplacement);

            // infranchissable
            if (coutMvt == std::numeric_limits<Stat>::max())
                continue;

            Stat nvCout = coutJusqua[courante] + coutMvt;

            // trop loin
            if (nvCout > uniteEnDeplacement->getCapaciteDeplacement())
                continue;

            // ZOC ennemie : on peut s'y arreter mais pas traverser
            bool dansZoc = caseDansZocEnnemie(suiv, *uniteEnDeplacement, zoc);
            if (dansZoc && suiv != arrivee)
                continue; // bloque la traversee (sauf si c'est la destination)

            if (!coutJusqua.count(suiv) || nvCout < coutJusqua[suiv]) {
                coutJusqua[suiv] = nvCout;
                Stat priorite = nvCout + calculDistance(*suiv, *arrivee);
                aExplorer.push({priorite, suiv});
                vientDe[suiv] = courante;
            }
        }
    }

    if (!vientDe.count(arrivee)) return {};
    return reconstruitChemin(vientDe, depart, arrivee);
}

std::size_t Carte::nbUnites(Faction faction) const
{
    std::size_t sum = 0;

    for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            Case *c = accesCase({static_cast<int>(q), static_cast<int>(r)});

            if (c->getFaction() == faction)
                sum += c->nbUnites();
        }
    }

    return sum;
}

std::vector<Case *> Carte::getCasesFactionAvecUnites(Faction faction) const
{
    std::vector<Case *> res;

    for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            Case *c = accesCase({static_cast<int>(q), static_cast<int>(r)});
            if (c->nbUnites() > 0 && c->getFaction() == faction)
                res.push_back(c);
        }
    }

    return res;
}

void Carte::effectuerEffetsCases()
{
    for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            Case *c = accesCase({static_cast<int>(q), static_cast<int>(r)});

            // seules les cases terrestres ont des effets (car des constructions)
            auto caseTerrestre = dynamic_cast<CaseTerrestre *>(c);
            if (caseTerrestre)
                caseTerrestre->effectuerEffetConstruction();
        }
    }
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
            auto c = accesCase({static_cast<int>(q), static_cast<int>(r)});

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
                os << "Atteignables par " << u->getNom() << " = ";
                auto casesAtte = getCasesAtteignables(c, u);
                for (const auto &ca : casesAtte) {
                    ca.first->sortieFlux(os);
                    os <<  "(" << ca.second << ") ";
                }
                os << std::endl;

                os << "Attaquables par " << u->getNom() << " = ";
                auto casesAtta = getCasesAttaquables(c, u);
                for (const auto &ca : casesAtta)
                    ca->sortieFlux(os);
                os << std::endl;
            }
        }
    }
}

std::vector<Case *> Carte::getVoisines(const Case &c) const
{
    std::vector<Case *> voisines;

    auto pos = c.getPos();
    auto directions = (pos.getQ() % 2 == 0) ? _DIRECTIONS_PAIRES : _DIRECTIONS_IMPAIRES;

    for (const auto &d : directions) {
        auto posVoisine = pos + d;
        if (positionValide(posVoisine))
            voisines.push_back(accesCase(posVoisine));
    }

    return voisines;
}

std::map<Case *, std::set<Faction>> Carte::getZOC() const
{
    std::map<Case *, std::set<Faction>> zoc;

    for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            Case *c = accesCase({static_cast<int>(q), static_cast<int>(r)});

            // la case elle-même + ses voisines sont sous ZOC de cette faction
            Faction f = c->getFaction();
            zoc[c].insert(f);
            for (Case *v : getVoisines(*c))
                zoc[v].insert(f);
        }
    }

    return zoc;
}

bool Carte::caseDansZocEnnemie(Case *caseCible, const Unite &uniteEnDeplacement,
                               const std::map<Case *, std::set<Faction>> &zoc) const
{
    auto it = zoc.find(caseCible);
    if (it == zoc.end())
        return false;

    for (Faction f : it->second) {
        if (f != Faction::neutre && f != uniteEnDeplacement.getFaction())
            return true;
    }

  return false;
}

distance Carte::calculDistance(const Case &a, const Case &b)
{
    // conversion offset vers axial (colonnes paires non decalees)
    auto versAxial = [](int q, int r) -> std::pair<int, int> {
        return { q, r - (q - (q & 1)) / 2 };
    };

    auto [aq, ar] = versAxial(a.getPos().getQ(), a.getPos().getR());
    auto [bq, br] = versAxial(b.getPos().getQ(), b.getPos().getR());

    int dq = aq - bq;
    int dr = ar - br;
    // ds = -dq - dr et distance = (|dq| + |dr| + |ds|) / 2
    return (std::abs(dq) + std::abs(dr) + std::abs(dq + dr)) / 2;
}

std::vector<Case *> Carte::reconstruitChemin(const std::map<Case *, Case *> &vientDe,
                                             Case *depart, Case *arrivee)
{
    std::vector<Case *> chemin;
    Case *courant = arrivee;

    // remonte de l'arrivee vers le depart
    while (!(courant == depart)) {
        chemin.push_back(courant);

        auto it = vientDe.find(courant);
        if (it == vientDe.end()) // securite (chemin casse)
            return {};
        courant = it->second;
    }

    chemin.push_back(depart); // ajouter le depart

    // inverser pour avoir depart vers arrivee
    std::reverse(chemin.begin(), chemin.end());

    return chemin;
}
