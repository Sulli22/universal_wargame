#include "sousmarin.hh"

SousMarin::SousMarin(Faction faction, stat pointsVie, stat nbMunitions,
                     stat nbProvisions, stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, Visibilite::nulle),
    UniteMarine(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier, Visibilite::nulle)
{}

std::string SousMarin::getNom() const
{
    return "Sous-Marin";
}

stat SousMarin::getPointsAttaqueLegere() const
{
    return 25;
}

stat SousMarin::getPointsAttaqueLourde() const
{
    return 40;
}

stat SousMarin::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    stat capaciteReelle = 10;
    stat capaciteMin = Unite::getNbProvisions();
    return std::min(capaciteMin, capaciteReelle);
}

stat SousMarin::getDistanceAttaque() const
{
    return 15;
}
