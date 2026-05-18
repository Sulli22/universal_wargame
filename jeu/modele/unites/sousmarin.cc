#include "sousmarin.hh"

SousMarin::SousMarin(Faction faction, Stat pointsVie, Stat nbMunitions,
                     Stat nbProvisions, Stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, Visibilite::nulle),
    UniteMarine(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier, Visibilite::nulle)
{}

std::string SousMarin::getNom() const
{
    return "Sous-Marin";
}

Stat SousMarin::getPointsAttaqueLegere() const
{
    return 25;
}

Stat SousMarin::getPointsAttaqueLourde() const
{
    return 40;
}

Stat SousMarin::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    Stat capacite = 3;
    Stat capaciteMin = Unite::getNbProvisions();
    return std::min(capaciteMin, capacite);
}

Stat SousMarin::getDistanceAttaque() const
{
    return 7;
}
