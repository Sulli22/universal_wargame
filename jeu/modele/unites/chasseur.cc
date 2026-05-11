#include "chasseur.hh"

Chasseur::Chasseur(Faction faction, stat pointsVie, stat nbMunitions,
                   stat nbProvisions, stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, Visibilite::partielle),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                    Visibilite::partielle)
{}

std::string Chasseur::getNom() const
{
    return "Chasseur";
}

stat Chasseur::getPointsAttaqueLegere() const
{
    return 12;
}

stat Chasseur::getPointsAttaqueLourde() const
{
    return 18;
}

stat Chasseur::getCapaciteDeplacement() const
{
    return 8;
}

stat Chasseur::getDistanceAttaque() const
{
    return 3;
}
