#include "infanterie.hh"

Infanterie::Infanterie(Faction faction, usint pointsVie, usint nbMunitions,
                       usint nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Infanterie::getNom() const
{
    return "Infanterie";
}

usint Infanterie::getPointsAttaqueLegere() const
{
    return 10;
}

usint Infanterie::getPointsAttaqueLourde() const
{
    return 12;
}

usint Infanterie::getCapaciteDeplacement() const
{
    return 4;
}

usint Infanterie::getDistanceAttaque() const
{
    return 1;
}

usint Infanterie::getTaille() const
{
    return 1;
}
