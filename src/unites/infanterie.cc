#include "infanterie.hh"

Infanterie::Infanterie(usint pointsVie, usint nbMunitions, usint nbProvisions) :
    Unite(pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(pointsVie, nbMunitions, nbProvisions)
{}

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
    return 2;
}

usint Infanterie::getDistanceAttaque() const
{
    return 1;
}

std::string Infanterie::getNom() const
{
    return "Infanterie";
}

usint Infanterie::getTaille() const
{
    return 1;
}
