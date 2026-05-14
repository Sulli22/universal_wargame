#include "bombardier.hh"

Bombardier::Bombardier(Faction faction, Stat pointsVie, Stat nbMunitions,
                       Stat nbProvisions, Stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Bombardier::getNom() const
{
    return "Bombardier";
}

Stat Bombardier::getPointsAttaqueLegere() const
{
    return 20;
}

Stat Bombardier::getPointsAttaqueLourde() const
{
    return 30;
}

Stat Bombardier::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    Stat capacite = 3;
    Stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capacite);
}

Stat Bombardier::getDistanceAttaque() const
{
    return 2;
}
