#include "sousmarin.hh"

SousMarin::SousMarin(Faction faction, usint pointsVie, usint nbMunitions,
                     usint nbProvisions, usint pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, Visibilite::nulle),
    UniteMarine(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier, Visibilite::nulle)
{}

std::string SousMarin::getNom() const
{
    return "Sous-Marin";
}

usint SousMarin::getPointsAttaqueLegere() const
{
    return 25;
}

usint SousMarin::getPointsAttaqueLourde() const
{
    return 40;
}

usint SousMarin::getCapaciteDeplacement() const
{
    return 10;
}

usint SousMarin::getDistanceAttaque() const
{
    return 20;
}
