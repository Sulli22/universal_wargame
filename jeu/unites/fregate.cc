#include "fregate.hh"

Fregate::Fregate(Faction faction, usint pointsVie, usint nbMunitions,
                 usint nbProvisions, usint pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteMarine(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Fregate::getNom() const
{
    return "Fregate";
}

usint Fregate::getPointsAttaqueLegere() const
{
    return 5;
}

usint Fregate::getPointsAttaqueLourde() const
{
    return 18;
}

usint Fregate::getCapaciteDeplacement() const
{
    return 3;
}

usint Fregate::getDistanceAttaque() const
{
    return 5;
}
