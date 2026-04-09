#include "bombardier.hh"

Bombardier::Bombardier(Faction faction, usint pointsVie, usint nbMunitions,
                       usint nbProvisions, usint pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Bombardier::getNom() const
{
    return "Bombardier";
}

usint Bombardier::getPointsAttaqueLegere() const
{
    return 20;
}

usint Bombardier::getPointsAttaqueLourde() const
{
    return 30;
}

usint Bombardier::getCapaciteDeplacement() const
{
    return 6;
}

usint Bombardier::getDistanceAttaque() const
{
    return 1;
}
