#include "artillerie.hh"

Artillerie::Artillerie(Faction faction, usint pointsVie, usint nbMunitions,
                       usint nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Artillerie::getNom() const
{
    return "Artillerie";
}

usint Artillerie::getPointsAttaqueLegere() const
{
    return 10;
}

usint Artillerie::getPointsAttaqueLourde() const
{
    return 18;
}

usint Artillerie::getCapaciteDeplacement() const
{
    return 3;
}

usint Artillerie::getDistanceAttaque() const
{
    return 3;
}

usint Artillerie::getTaille() const
{
    return 2;
}
