#include "model.hh"
#include <algorithm>

Model::Model(unsigned int idGuerre, Faction faction1, Faction faction2):
    _plateau(idGuerre), _faction1(faction1), _faction2(faction2),

    // seuil de defaite = 5% du nb initial
    _seuilDefaiteFaction1(_plateau.nbUnites(_faction1) * 0.05),
    _seuilDefaiteFaction2(_plateau.nbUnites(_faction2) * 0.05),

    _factionAttaquante(_faction1), _factionAttaquee(_faction2),

    _caseSelectionnee(nullptr), _indUniteSelectionnee(0),
    _caseCible(nullptr),

    _etat(etat::selection)
{
    if (_faction1 == _faction2)
        throw std::invalid_argument("Erreur : les factions doivent etre adverses");

    if (_faction1 == Faction::neutre || _faction2 == Faction::neutre)
        throw std::invalid_argument("Erreur : les factions ne peuvent pas etre neutres");
}

Faction Model::getFaction1() const
{
    return _faction1;
}

Faction Model::getFaction2() const
{
    return _faction2;
}

Faction Model::getFactionAttaquante() const
{
    return _factionAttaquante;
}

Faction Model::getFactionAttaquee() const
{
    return _factionAttaquee;
}

Case *Model::getCaseSelectionnee() const
{
    return _caseSelectionnee;
}

Case *Model::getCaseCible() const
{
    return _caseCible;
}

void Model::setEtat(etat nvEtat)
{
    _etat = nvEtat;
}

bool Model::factionEstPerdante(Faction faction) const
{
    if (faction == _faction1)
        return _plateau.nbUnites(_faction1) < _seuilDefaiteFaction1;

    if(faction == _faction2)
        return _plateau.nbUnites(_faction2) < _seuilDefaiteFaction2;

    throw std::invalid_argument("Erreur : la faction est incorrecte");
}

bool Model::partieFinie() const
{
    return factionEstPerdante(_faction1) || factionEstPerdante(_faction2);
}

Faction Model::factionVictorieuse() const
{
    if (!partieFinie())
        throw std::runtime_error("Erreur : la partie n'est pas finie");

    return factionEstPerdante(_faction2) ? _faction1 : _faction2;
}

void Model::changementJoueur()
{
    // raz
    _caseSelectionnee = nullptr;
    _caseCible = nullptr;
    _unitesAyantJoue.clear();

    // permutation factions
    Faction factionTmp = _factionAttaquante;
    _factionAttaquante = _factionAttaquee;
    _factionAttaquee = factionTmp;
}

std::vector<Case *> Model::getCasesConcernees() const
{
    std::vector<Case *> res;

    switch (_etat) {
    case etat::selection:
        res = _plateau.getCasesFaction(_factionAttaquante);
        break;

    case etat::deplacement:
        res = keysFromMap(_plateau.getCasesAtteignables(_caseSelectionnee, getUniteSelectionee()));
        break;

    case etat::attaque:
        res = _plateau.getCasesAttaquables(_caseSelectionnee, getUniteSelectionee());
        break;

    case etat::construction:
        res = _plateau.getVoisines(*_caseSelectionnee);
        break;
    }

    return res;
}

void Model::selectionnerCase(const Position &pos)
{
    Case *c = _plateau.accesCase(pos);

    if (!c)
        throw std::runtime_error("Erreur : la nouvelle case selectionnee est invalide");

    auto casesConcernees = getCasesConcernees();
    auto itc = std::find(casesConcernees.begin(), casesConcernees.end(), c);

    switch (_etat) {
    case etat::selection:
        if (itc != casesConcernees.end()) {
            if (_caseSelectionnee != c) {   // si on change de case selectionnee
                _caseSelectionnee = c;
                _indUniteSelectionnee = 0;
            }
            else    // sinon on reste sur la meme case
                _indUniteSelectionnee = (_indUniteSelectionnee + 1) % (_caseSelectionnee->nbUnites() + 1);
        }
        else    // on considere que aucune case n'est selectionnee
            _caseSelectionnee = nullptr;
        break;

    case etat::deplacement:
    case etat::attaque:
    case etat::construction:
        _caseCible = (itc != casesConcernees.end()) ? c : nullptr;
        break;
    }
}

Unite *Model::getUniteSelectionee() const
{
    if (!_caseSelectionnee)
        throw std::runtime_error("Erreur : Aucune case n'est selectionee");

    return _caseSelectionnee->getUnite(_indUniteSelectionnee);
}

usint Model::getNbActionsPossibles() const
{
    if (uniteSelectioneeAJoue())
        return 0;
    return getUniteSelectionee()->getNbActionsPossibles();
}

bool Model::uniteSelectioneeAJoue() const
{
    if (_unitesAyantJoue.empty())
        return false;

    return _unitesAyantJoue.find(getUniteSelectionee()) == _unitesAyantJoue.end();
}

void Model::choixAction(usint indAction)
{
    if (indAction >= getNbActionsPossibles())
        throw std::invalid_argument("Erreur : l'indice est incorrecte");

    switch (indAction) {
    case 0:     setEtat(etat::deplacement);     break;
    case 1:     setEtat(etat::attaque);         break;
    case 2:     setEtat(etat::construction);    break;
    }
}

void Model::effectuerAction()
{
    if (!_caseSelectionnee)
        throw std::runtime_error("Erreur : aucune case selectionnee");

    if (!_caseCible)
        throw std::runtime_error("Erreur : aucune case cible");

    switch (_etat) {
    case etat::deplacement:
        // pas tres clair, la deuxieme ligne recupere la distance de deplacement
        _caseSelectionnee->deplacerUnite(_indUniteSelectionnee, _caseCible,
            _plateau.getCasesAtteignables(_caseSelectionnee, getUniteSelectionee()).at(getCaseCible()));
        break;

    case etat::attaque:
        for (auto &unite : _caseCible->getUnites())
            getUniteSelectionee()->attaquerUnite(unite);
        break;

    case etat::construction:
        //auto genie = dynamic_cast<Genie *>(getUniteSelectionee());
        //genie->construire(_caseCible, )
        break;

    default:
        throw std::runtime_error("Erreur : impossible d'effectuer l'action");
    }

    //_unitesAyantJoue.insert(getUniteSelectionee());
    _caseSelectionnee = nullptr;
    _caseCible = nullptr;
    setEtat(etat::selection);

    if (_unitesAyantJoue.size() == _plateau.nbUnites(_factionAttaquante))
        changementJoueur();
}

void Model::sortieFlux(std::ostream &os) const
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

    _plateau.accesCase({1, 0})->afficherDetails(os);
}

std::string Model::factionToString(Faction faction)
{
    switch (faction) {
    case Faction::bleue:    return "bleue";
    case Faction::rouge:    return "rouge";
    case Faction::neutre:   return "neutre";

    default:
        throw std::invalid_argument("Erreur : faction invalide");
    }
}

std::vector<Case *> Model::keysFromMap(const std::map<Case *, usint> &map)
{
    std::vector<Case *> keys;
    for (const auto &[key, val] : map)
        keys.push_back(key);
    return keys;
}
