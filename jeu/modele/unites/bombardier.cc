#include "bombardier.hh"

Bombardier::Bombardier(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                       uint16_t nbProvisions, uint16_t pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Bombardier::getNom() const
{
    return "Bombardier";
}

uint16_t Bombardier::getPointsAttaqueLegere() const
{
    return 20;
}

uint16_t Bombardier::getPointsAttaqueLourde() const
{
    return 30;
}

uint16_t Bombardier::getCapaciteDeplacement() const
{
    return 4;
}

uint16_t Bombardier::getDistanceAttaque() const
{
    return 1;
}
