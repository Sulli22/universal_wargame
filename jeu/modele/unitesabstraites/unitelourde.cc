#include "unitelourde.hh"

UniteLourde::UniteLourde(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                         uint16_t nbProvisions, uint16_t pointsBouclier, Visibilite visibilite):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, visibilite),
    _pointsBouclier(pointsBouclier), _MAX_POINTS_BOUCLIER(pointsBouclier)
{}

uint16_t UniteLourde::getPointsBouclier() const
{
    return _pointsBouclier;
}

uint16_t UniteLourde::getMaxPointsBouclier() const
{
    return _MAX_POINTS_BOUCLIER;
}

void UniteLourde::reparerBouclier()
{
    _pointsBouclier = _MAX_POINTS_BOUCLIER;
}

bool UniteLourde::estLegere() const
{
    return false;
}

void UniteLourde::sortieFlux(std::ostream &os) const
{
    Unite::sortieFlux(os);
    os << " pointsBouclier=" << _pointsBouclier << "/" << _MAX_POINTS_BOUCLIER;
}

void UniteLourde::prendreDegats(uint16_t degats)
{
    int nvPointsBouclier = _pointsBouclier - degats;
    if (nvPointsBouclier < 0) {
        _pointsBouclier = 0;
        Unite::prendreDegats(-1 * nvPointsBouclier);
    }
    else
        _pointsBouclier = nvPointsBouclier;
}
