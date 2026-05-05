#include "fregate.hh"

Fregate::Fregate(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                 uint16_t nbProvisions, uint16_t pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteMarine(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Fregate::getNom() const
{
    return "Fregate";
}

uint16_t Fregate::getPointsAttaqueLegere() const
{
    return 5;
}

uint16_t Fregate::getPointsAttaqueLourde() const
{
    return 18;
}

uint16_t Fregate::getCapaciteDeplacement() const
{
    return 3;
}

uint16_t Fregate::getDistanceAttaque() const
{
    return 5;
}
