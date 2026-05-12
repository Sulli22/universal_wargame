#include "fregate.hh"

Fregate::Fregate(Faction faction, stat pointsVie, stat nbMunitions,
                 stat nbProvisions, stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteMarine(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Fregate::getNom() const
{
    return "Fregate";
}

stat Fregate::getPointsAttaqueLegere() const
{
    return 5;
}

stat Fregate::getPointsAttaqueLourde() const
{
    return 18;
}

stat Fregate::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    stat capacite = 3;
    stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capacite);
}

stat Fregate::getDistanceAttaque() const
{
    return 4;
}
