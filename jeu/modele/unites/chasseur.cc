#include "chasseur.hh"

Chasseur::Chasseur(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                   uint16_t nbProvisions, uint16_t pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, Visibilite::partielle),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                    Visibilite::partielle)
{}

std::string Chasseur::getNom() const
{
    return "Chasseur";
}

uint16_t Chasseur::getPointsAttaqueLegere() const
{
    return 12;
}

uint16_t Chasseur::getPointsAttaqueLourde() const
{
    return 18;
}

uint16_t Chasseur::getCapaciteDeplacement() const
{
    return 8;
}

uint16_t Chasseur::getDistanceAttaque() const
{
    return 3;
}
