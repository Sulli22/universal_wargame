#include "model.hh"

Model::Model(unsigned int idGuerre, Faction faction1, Faction faction2):
    _plateau(idGuerre), _faction1(faction1), _faction2(faction2),

    // seuil de defaite = 5% du nb initial
    _seuilDefaiteFaction1(_plateau.nbUnites(_faction1) * 0.05),
    _seuilDefaiteFaction2(_plateau.nbUnites(_faction2) * 0.05),

    _factionAttaquante(_faction1), _factionAttaquee(_faction2)
{
    if (_faction1 == _faction2)
        throw std::invalid_argument("Erreur : les factions doivent etre adverses");

    if (_faction1 == Faction::neutre || _faction2 == Faction::neutre)
        throw std::invalid_argument("Erreur : les factions ne peuvent pas etre neutres");
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
    Faction factionTmp = _factionAttaquante;
    _factionAttaquante = _factionAttaquee;
    _factionAttaquee = factionTmp;
}

void Model::sortieFlux(std::ostream &os) const
{
    os << "Faction attaquante = " << factionToString(_factionAttaquante) << std::endl
       << "Faction attaquee = " << factionToString(_factionAttaquee) << std::endl
       << "Partie finie ? " << partieFinie() << " (0 = Non, 1 = Oui)" << std::endl
       << "==> Plateau" << std::endl;

    _plateau.soriteFlux(os);
    _plateau.afficherDetails(os);
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
