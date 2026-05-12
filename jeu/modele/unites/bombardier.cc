#include "bombardier.hh"

Bombardier::Bombardier(Faction faction, stat pointsVie, stat nbMunitions,
                       stat nbProvisions, stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteAerienne(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Bombardier::getNom() const
{
    return "Bombardier";
}

stat Bombardier::getPointsAttaqueLegere() const
{
    return 20;
}

stat Bombardier::getPointsAttaqueLourde() const
{
    return 30;
}

stat Bombardier::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    stat capaciteReelle = 4;
    stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capaciteReelle);
}

stat Bombardier::getDistanceAttaque() const
{
    return 1;
}
