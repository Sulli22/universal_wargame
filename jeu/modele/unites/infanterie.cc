#include "infanterie.hh"

Infanterie::Infanterie(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                       uint16_t nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Infanterie::getNom() const
{
    return "Infanterie";
}

uint16_t Infanterie::getPointsAttaqueLegere() const
{
    return 10;
}

uint16_t Infanterie::getPointsAttaqueLourde() const
{
    return 12;
}

uint16_t Infanterie::getCapaciteDeplacement() const
{
    return 4;
}

uint16_t Infanterie::getDistanceAttaque() const
{
    return 1;
}

uint16_t Infanterie::getTaille() const
{
    return 1;
}
