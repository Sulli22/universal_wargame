#include "unitelourde.hh"

UniteLourde::UniteLourde(usint pointsVie, usint pointsBouclier,
                         usint nbMunitions) :
    Unite(pointsVie, nbMunitions), _pointsBouclier(pointsBouclier)
{}

usint UniteLourde::getPointsBouclier() const
{
    return _pointsBouclier;
}

bool UniteLourde::estLegere() const
{
    return false;
}

void UniteLourde::prendreDegats(usint degats)
{
    int nvPointsBouclier = _pointsBouclier - degats;
    if (nvPointsBouclier < 0) {
        _pointsBouclier = 0;
        Unite::prendreDegats(-1 * nvPointsBouclier);
    } else {
        _pointsBouclier = nvPointsBouclier;
    }
}
