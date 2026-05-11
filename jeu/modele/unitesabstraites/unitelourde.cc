#include "unitelourde.hh"

UniteLourde::UniteLourde(Faction faction, stat pointsVie, stat nbMunitions,
                         stat nbProvisions, stat pointsBouclier, Visibilite visibilite):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, visibilite),
    _pointsBouclier(pointsBouclier), _MAX_POINTS_BOUCLIER(pointsBouclier)
{}

stat UniteLourde::getPointsBouclier() const
{
    return _pointsBouclier;
}

stat UniteLourde::getMaxPointsBouclier() const
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

void UniteLourde::prendreDegats(stat degats)
{
    int nvPointsBouclier = _pointsBouclier - degats;
    if (nvPointsBouclier < 0) {
        _pointsBouclier = 0;
        Unite::prendreDegats(-1 * nvPointsBouclier);
    }
    else
        _pointsBouclier = nvPointsBouclier;
}
