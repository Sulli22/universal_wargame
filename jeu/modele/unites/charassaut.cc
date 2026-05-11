#include "charassaut.hh"

CharAssaut::CharAssaut(Faction faction, stat pointsVie, stat nbMunitions,
                       stat nbProvisions, stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLourde(faction, pointsVie, nbMunitions, nbProvisions,
                           pointsBouclier)
{}

std::string CharAssaut::getNom() const
{
    return "Char d'assaut";
}

stat CharAssaut::getPointsAttaqueLegere() const
{
    return 8;
}

stat CharAssaut::getPointsAttaqueLourde() const
{
    return 18;
}

stat CharAssaut::getCapaciteDeplacement() const
{
    return 3;
}

stat CharAssaut::getDistanceAttaque() const
{
    return 3;
}
