#include "model.hh"
#include <algorithm>

Model::Model(unsigned int idGuerre, Faction faction1, Faction faction2):
    _plateau(idGuerre), _faction1(faction1), _faction2(faction2),

    // seuil de defaite = 5% du nb initial
    _seuilDefaiteFaction1(_plateau.nbUnites(_faction1) * 0.05),
    _seuilDefaiteFaction2(_plateau.nbUnites(_faction2) * 0.05),

    _factionAttaquante(_faction1), _factionAttaquee(_faction2),

    _caseSelectionnee(nullptr), _indUniteSelectionnee(0)
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
    // raz unites ayant joue
    _unitesAyantJoue.clear();

    // permutation factions
    Faction factionTmp = _factionAttaquante;
    _factionAttaquante = _factionAttaquee;
    _factionAttaquee = factionTmp;
}

std::vector<Case *> Model::getCasesFactionAttaquante() const
{
    return _plateau.getCasesFaction(_factionAttaquante);
}

void Model::selectionnerCase(const Position &pos)
{
    Case *c = _plateau.accesCase(pos);

    if (!c)
        throw std::runtime_error("Erreur : la nouvelle case selectionnee est invalide");

    auto casesFactionAttaquante = getCasesFactionAttaquante();
    auto itc = std::find(casesFactionAttaquante.begin(), casesFactionAttaquante.end(), c);
    if (itc != casesFactionAttaquante.end()) {
        if (_caseSelectionnee != c) {   // si on change de case selectionnee
            _caseSelectionnee = c;
            _indUniteSelectionnee = 0;
        }
        else    // sinon on reste sur la meme case
            _indUniteSelectionnee = (_indUniteSelectionnee + 1) % (_caseSelectionnee->nbUnites() + 1);
    }
    else
        _caseSelectionnee = nullptr;    // on considere que aucune case n'est selectionnee
}

Unite *Model::getUniteSelectionee() const
{
    if (!_caseSelectionnee)
        std::runtime_error("Erreur : Aucune case n'est selectionee");

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
    return _unitesAyantJoue.find(getUniteSelectionee()) == _unitesAyantJoue.end();
}

void Model::effectuerAction(usint indAction)
{
    if (indAction >= getNbActionsPossibles())
        throw std::invalid_argument("Erreur : l'indice est incorrecte");

    switch (indAction) {
        case 0: break;
        case 1: break;
        case 2: break;
        default: break;
    }
}

void Model::sortieFlux(std::ostream &os) const
{
    os << "Faction attaquante = " << factionToString(_factionAttaquante) << std::endl
       << "Faction attaquee = " << factionToString(_factionAttaquee) << std::endl
       << "Partie finie ? " << partieFinie() << " (0 = Non, 1 = Oui)" << std::endl
       << "==> Plateau" << std::endl;

    //_plateau.soriteFlux(os);

    //_plateau.afficherDetails(os);

    os << "Cases de la faction attaquante : ";
    for (const auto &c : getCasesFactionAttaquante())
        c->sortieFlux(os);
    os << std::endl;

    if (_caseSelectionnee){
        os << "Case selectionnee : ";
        _caseSelectionnee->sortieFlux(os); os << std::endl;
        os << "Indice unite : " << _indUniteSelectionnee << std::endl;
    }
    else
        os << "Aucune case selectionnee" << std::endl;
}

std::string Model::factionToString(Faction faction)
{
    switch (faction) {
        case Faction::bleue: return "bleue";
        case Faction::rouge: return "rouge";
        case Faction::neutre: return "neutre";
        default:
            throw std::invalid_argument("Erreur : faction invalide");
    }
}
