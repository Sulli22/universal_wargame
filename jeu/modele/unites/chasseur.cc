#include "chasseur.hh"

Chasseur::Chasseur(Faction faction, Stat pointsVie, Stat nbMunitions,
                   Stat nbProvisions, Stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, Visibilite::partielle),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                    Visibilite::partielle)
{}

std::string Chasseur::getNom() const
{
    return "Chasseur";
}

Stat Chasseur::getPointsAttaqueLegere() const
{
    return 12;
}

Stat Chasseur::getPointsAttaqueLourde() const
{
    return 18;
}

Stat Chasseur::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    Stat capacite = 5;
    Stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capacite);
}

Stat Chasseur::getDistanceAttaque() const
{
    return 2;
}
