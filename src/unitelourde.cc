#include "unitelourde.hh"

UniteLourde::UniteLourde(unsigned int pointsVie,
                         unsigned int pointsBouclier,
                         unsigned int nbMunitions)
    : Unite(pointsVie, nbMunitions), _pointsBouclier(pointsBouclier)
{}

unsigned int UniteLourde::getPointsBouclier() const
{
    return _pointsBouclier;
}

bool UniteLourde::estLegere() const
{
    return false;
}

void UniteLourde::prendreDegats(unsigned int degats)
{
    int nvPointsBouclier = _pointsBouclier - degats;
    if (nvPointsBouclier < 0) {
        _pointsBouclier = 0;
        Unite::prendreDegats(-1 * nvPointsBouclier);
    } else {
        _pointsBouclier = nvPointsBouclier;
    }
}
