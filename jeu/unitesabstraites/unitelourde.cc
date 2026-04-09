#include "unitelourde.hh"

UniteLourde::UniteLourde(Faction faction, usint pointsVie, usint nbMunitions,
                         usint nbProvisions, usint pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    _pointsBouclier(pointsBouclier), _MAX_POINTS_BOUCLIER(pointsBouclier)
{}

usint UniteLourde::getPointsBouclier() const
{
    return _pointsBouclier;
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

void UniteLourde::prendreDegats(usint degats)
{
    int nvPointsBouclier = _pointsBouclier - degats;
    if (nvPointsBouclier < 0) {
        _pointsBouclier = 0;
        Unite::prendreDegats(-1 * nvPointsBouclier);
    }
    else
        _pointsBouclier = nvPointsBouclier;
}
