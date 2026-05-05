#include "artillerie.hh"

Artillerie::Artillerie(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                       uint16_t nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Artillerie::getNom() const
{
    return "Artillerie";
}

uint16_t Artillerie::getPointsAttaqueLegere() const
{
    return 10;
}

uint16_t Artillerie::getPointsAttaqueLourde() const
{
    return 18;
}

uint16_t Artillerie::getCapaciteDeplacement() const
{
    return 3;
}

uint16_t Artillerie::getDistanceAttaque() const
{
    return 3;
}

uint16_t Artillerie::getTaille() const
{
    return 2;
}
