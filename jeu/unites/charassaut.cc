#include "charassaut.hh"

CharAssaut::CharAssaut(Faction faction, usint pointsVie, usint nbMunitions,
                       usint nbProvisions, usint pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLourde(faction, pointsVie, nbMunitions, nbProvisions,
                           pointsBouclier)
{}

std::string CharAssaut::getNom() const
{
    return "Char d'assaut";
}

usint CharAssaut::getPointsAttaqueLegere() const
{
    return 8;
}

usint CharAssaut::getPointsAttaqueLourde() const
{
    return 18;
}

usint CharAssaut::getCapaciteDeplacement() const
{
    return 3;
}

usint CharAssaut::getDistanceAttaque() const
{
    return 3;
}
