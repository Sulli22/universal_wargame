#include "modele.hh"
#include "depotmunitions.hh"
#include "depotprovisions.hh"
#include "genie.hh"
#include "infirmerie.hh"
#include "pont.hh"
#include <algorithm>
#include <iostream>

Modele::Modele(unsigned int idGuerre, Faction faction1, Faction faction2):
    _plateau(idGuerre), _etat(etat::selection),

    _faction1(faction1), _faction2(faction2),
    _factionAttaquante(_faction1), _factionAttaquee(_faction2),

    // seuil de defaite = 5% du nb initial
    _seuilDefaiteFaction1(_plateau.nbUnites(_faction1) * 0.05),
    _seuilDefaiteFaction2(_plateau.nbUnites(_faction2) * 0.05),

    _caseSelectionnee(nullptr), _indUniteSelectionnee(0),
    _caseCible(nullptr), _aConstruire(nullptr)
{
    if (_faction1 == _faction2)
        throw std::invalid_argument("Erreur : les factions doivent etre adverses");

    if (_faction1 == Faction::neutre || _faction2 == Faction::neutre)
        throw std::invalid_argument("Erreur : les factions ne peuvent pas etre neutres");
}

Faction Modele::getFactionAttaquante() const
{
    return _factionAttaquante;
}

Case *Modele::getCaseSelectionnee() const
{
    return _caseSelectionnee;
}

Case *Modele::getCaseCible() const
{
    return _caseCible;
}

void Modele::setEtat(etat nvEtat)
{
    _etat = nvEtat;
}

bool Modele::factionEstPerdante(Faction faction) const
{
    if (faction == _faction1)
        return _plateau.nbUnites(_faction1) < _seuilDefaiteFaction1;

    if (faction == _faction2)
        return _plateau.nbUnites(_faction2) < _seuilDefaiteFaction2;

    throw std::invalid_argument("Erreur : la faction est incorrecte");
}

bool Modele::partieFinie() const
{
    return factionEstPerdante(_faction1) || factionEstPerdante(_faction2);
}

Faction Modele::getFactionVictorieuse() const
{
    if (!partieFinie())
        throw std::runtime_error("Erreur : la partie n'est pas finie");

    return factionEstPerdante(_faction2) ? _faction1 : _faction2;
}

void Modele::changerJoueur()
{
    // raz
    annulerSelections();
    _unitesAyantJoue.clear();

    // actions des cases
    _plateau.effectuerActionsCases();

    // permutation factions
    Faction factionTmp = _factionAttaquante;
    _factionAttaquante = _factionAttaquee;
    _factionAttaquee = factionTmp;
}

std::vector<Case *> Modele::getCasesConcernees() const
{
    std::vector<Case *> res;

    switch (_etat) {
    case etat::selection:
        res = _plateau.getCasesFactionAvecUnites(_factionAttaquante);
        break;

    case etat::deplacement:
        res = keysFromMap(_plateau.getCasesAtteignables(_caseSelectionnee, getUniteSelectionee()));
        break;

    case etat::attaque:
        res = _plateau.getCasesAttaquables(_caseSelectionnee, getUniteSelectionee());
        break;

    case etat::construction:
        res = _plateau.getVoisinesConstructibles(*_caseSelectionnee);
        break;
    }

    return res;
}

bool Modele::positionValidePlateau(const Position &pos) const
{
    return _plateau.positionValide(pos);
}

std::size_t Modele::getLargeurPlateau() const
{
    return _plateau.getLargeur();
}

std::size_t Modele::getHauteurPlateau() const
{
    return _plateau.getHauteur();
}

Case *Modele::accesCasePlateau(const Position &pos) const
{
    return _plateau.accesCase(pos);
}

bool Modele::estConcernee(Case *c) const
{
    auto caseConcernees = getCasesConcernees();
    auto it = find(caseConcernees.begin(), caseConcernees.end(), c);

    return (it != caseConcernees.end());
}

bool Modele::cheminExiste() const
{
    return (_etat == etat::deplacement) && (_caseSelectionnee) && (_caseCible);
}

void Modele::selectionnerCase(const Position &pos)
{
    Case *c = _plateau.accesCase(pos);

    if (!c)
        throw std::runtime_error("Erreur : la nouvelle case selectionnee est invalide");

    bool estConcern = estConcernee(c);

    switch (_etat) {
    case etat::selection:
        if (estConcern) {
            if (_caseSelectionnee != c) {   // si on change de case selectionnee
                _caseSelectionnee = c;
                _indUniteSelectionnee = 0;
            }
            else    // sinon on reste sur la meme case
                _indUniteSelectionnee = (_indUniteSelectionnee + 1) % _caseSelectionnee->nbUnites();
        }
        else    // on considere que aucune case n'est selectionnee
            _caseSelectionnee = nullptr;
        break;

    case etat::deplacement:
    case etat::attaque:
    case etat::construction:
        _caseCible = estConcern ? c : nullptr;
        break;
    }
}

void Modele::annulerSelections()
{
    _caseSelectionnee = nullptr;
    _caseCible = nullptr;
    _aConstruire = nullptr;
    setEtat(etat::selection);
}

Unite *Modele::getUniteSelectionee() const
{
    if (!_caseSelectionnee)
        return nullptr;

    return _caseSelectionnee->getUnite(_indUniteSelectionnee);
}

uint16_t Modele::getNbActionsPossibles() const
{
    if (uniteSelectioneeAJoue())
        return 0;

    auto u = getUniteSelectionee();
    if (!u)
        return 0;

    return getUniteSelectionee()->getNbActionsPossibles();
}

bool Modele::uniteSelectioneeAJoue() const
{
    if (_unitesAyantJoue.empty())
        return false;

    return _unitesAyantJoue.find(getUniteSelectionee()) != _unitesAyantJoue.end();
}

void Modele::choixAction(uint16_t indAction)
{
    if (indAction >= getNbActionsPossibles())
        throw std::invalid_argument("Erreur : l'indice est incorrecte");

    switch (indAction) {
    case 0:     setEtat(etat::deplacement);     break;
    case 1:     setEtat(etat::attaque);         break;
    case 2:     setEtat(etat::construction);    break;
    }
}

void Modele::effectuerAction()
{
    if (_caseSelectionnee && _caseCible) {
        _unitesAyantJoue.insert(getUniteSelectionee());

        if (_etat == etat::deplacement) {
            auto path = getChemin();
            uint16_t distance = path.size()-1;
            _caseSelectionnee->deplacerUnite(_indUniteSelectionnee, _caseCible, distance);
        }

        else if (_etat == etat::attaque) {
            for (auto &unite : _caseCible->getUnites())
                getUniteSelectionee()->attaquerUnite(unite);
            _caseCible->supprimeNonUnitesOperationnelles();
        }

        else if (_etat == etat::construction && _aConstruire) {
            auto genie = dynamic_cast<Genie *>(getUniteSelectionee());
            auto caseCibleTerrestre = dynamic_cast<CaseTerrestre *>(_caseCible);
            genie->construire(caseCibleTerrestre, std::move(_aConstruire));
        }

        annulerSelections();

        if (_unitesAyantJoue.size() == _plateau.nbUnites(_factionAttaquante))
            changerJoueur();
    }

    // sinon on fait rien
}

uint16_t Modele::getNbConstructionsPossibles() const
{
    if (_etat != etat::construction || !_caseCible)
        return 0;

    return _caseCible->nbConstructionsPossibles();
}

void Modele::choixConstruction(uint16_t indConstruction)
{
    if (_etat != etat::construction || indConstruction >= getNbConstructionsPossibles())
        throw std::runtime_error("Erreur : impossible de choisir une construction");

    else {
        switch (indConstruction) {
        case 0:     _aConstruire = std::make_unique<DepotMunitions>();  break;
        case 1:     _aConstruire = std::make_unique<DepotProvisions>(); break;
        case 2:     _aConstruire = std::make_unique<Infirmerie>();      break;
        case 3:     _aConstruire = std::make_unique<Pont>();            break;
        }
    }
}

bool Modele::actionValidable() const
{
    if (!_caseSelectionnee || !_caseCible)
        return false;

    if (_etat == etat::construction)
        return _aConstruire.get();

    return true;
}

std::vector<Case *> Modele::getChemin() const
{
    if (!cheminExiste())
        throw std::runtime_error("Erreur : aucun chemin ne peut etre trouve");

    return _plateau.getChemin(_caseSelectionnee, _caseCible, getUniteSelectionee());
}

void Modele::sortieFlux(std::ostream &os) const
{
    os << "Faction attaquante = " << factionToString(_factionAttaquante) << std::endl
       << "Faction attaquee = " << factionToString(_factionAttaquee) << std::endl
       << "Partie finie ? " << partieFinie() << " (0 = Non, 1 = Oui)" << std::endl
       << "Etat = ";

    switch (_etat) {
        case etat::selection: os << "selection"; break;
        case etat::deplacement: os<< "deplacement"; break;
        case etat::attaque: os << "attaque"; break;
        case etat::construction: os << "construction"; break;
    }
    os << std::endl;

    os << "Cases concernees : ";
    for (const auto &c : getCasesConcernees())
        c->sortieFlux(os);
    os << std::endl;

    if (_caseSelectionnee) {
        os << "Case selectionnee : ";
        _caseSelectionnee->sortieFlux(os); os << std::endl;
        os << "Indice unite : " << _indUniteSelectionnee << std::endl;
        os << "Nombre actions possibles = " << getNbActionsPossibles() << std::endl;
    }
    else
        os << "Aucune case selectionnee" << std::endl;

    if (_caseCible) {
        os << "Case cible : ";
        _caseCible->sortieFlux(os); os << std::endl;
    }
    else
        os << "Aucune case cible" << std::endl;
}

std::string Modele::factionToString(Faction faction)
{
    switch (faction) {
    case Faction::bleue:    return "bleue";
    case Faction::rouge:    return "rouge";
    case Faction::neutre:   return "neutre";

    default:
        throw std::invalid_argument("Erreur : faction invalide");
    }
}

std::vector<Case *> Modele::keysFromMap(const std::map<Case *, uint16_t> &map)
{
    std::vector<Case *> keys;
    for (const auto &[key, val] : map)
        keys.push_back(key);
    return keys;
}
