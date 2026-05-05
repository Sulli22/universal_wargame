#include "charassaut.hh"

CharAssaut::CharAssaut(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                       uint16_t nbProvisions, uint16_t pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLourde(faction, pointsVie, nbMunitions, nbProvisions,
                           pointsBouclier)
{}

std::string CharAssaut::getNom() const
{
    return "Char d'assaut";
}

uint16_t CharAssaut::getPointsAttaqueLegere() const
{
    return 8;
}

uint16_t CharAssaut::getPointsAttaqueLourde() const
{
    return 18;
}

uint16_t CharAssaut::getCapaciteDeplacement() const
{
    return 3;
}

uint16_t CharAssaut::getDistanceAttaque() const
{
    return 3;
}
