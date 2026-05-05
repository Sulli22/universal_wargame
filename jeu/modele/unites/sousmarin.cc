#include "sousmarin.hh"

SousMarin::SousMarin(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                     uint16_t nbProvisions, uint16_t pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, Visibilite::nulle),
    UniteMarine(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier, Visibilite::nulle)
{}

std::string SousMarin::getNom() const
{
    return "Sous-Marin";
}

uint16_t SousMarin::getPointsAttaqueLegere() const
{
    return 25;
}

uint16_t SousMarin::getPointsAttaqueLourde() const
{
    return 40;
}

uint16_t SousMarin::getCapaciteDeplacement() const
{
    return 10;
}

uint16_t SousMarin::getDistanceAttaque() const
{
    return 15;
}
