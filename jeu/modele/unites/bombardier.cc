#include "bombardier.hh"

Bombardier::Bombardier(Faction faction, stat pointsVie, stat nbMunitions,
                       stat nbProvisions, stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Bombardier::getNom() const
{
    return "Bombardier";
}

stat Bombardier::getPointsAttaqueLegere() const
{
    return 20;
}

stat Bombardier::getPointsAttaqueLourde() const
{
    return 30;
}

stat Bombardier::getCapaciteDeplacement() const
{
    return 4;
}

stat Bombardier::getDistanceAttaque() const
{
    return 1;
}
