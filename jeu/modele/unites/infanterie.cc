#include "infanterie.hh"

Infanterie::Infanterie(Faction faction, stat pointsVie, stat nbMunitions,
                       stat nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Infanterie::getNom() const
{
    return "Infanterie";
}

stat Infanterie::getPointsAttaqueLegere() const
{
    return 10;
}

stat Infanterie::getPointsAttaqueLourde() const
{
    return 12;
}

stat Infanterie::getCapaciteDeplacement() const
{
    return 4;
}

stat Infanterie::getDistanceAttaque() const
{
    return 1;
}

stat Infanterie::getTaille() const
{
    return 1;
}
