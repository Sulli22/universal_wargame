#include "infanterie.hh"

Infanterie::Infanterie(usint pointsVie, usint nbMunitions, usint nbProvisions):
    Unite(pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(pointsVie, nbMunitions, nbProvisions)
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
    return 15;
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
