#include "chasseur.hh"

Chasseur::Chasseur(Faction faction, usint pointsVie, usint nbMunitions,
                   usint nbProvisions, usint pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, Visibilite::partielle),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                    Visibilite::partielle)
{}

std::string Chasseur::getNom() const
{
    return "Chasseur";
}

usint Chasseur::getPointsAttaqueLegere() const
{
    return 12;
}

usint Chasseur::getPointsAttaqueLourde() const
{
    return 18;
}

usint Chasseur::getCapaciteDeplacement() const
{
    return 8;
}

usint Chasseur::getDistanceAttaque() const
{
    return 3;
}
