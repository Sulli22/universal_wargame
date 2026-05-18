#include "fregate.hh"

Fregate::Fregate(Faction faction, Stat pointsVie, Stat nbMunitions,
                 Stat nbProvisions, Stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteMarine(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}

std::string Fregate::getNom() const
{
    return "Fregate";
}

Stat Fregate::getPointsAttaqueLegere() const
{
    return 5;
}

Stat Fregate::getPointsAttaqueLourde() const
{
    return 18;
}

Stat Fregate::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    Stat capacite = 5;
    Stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capacite);
}

Stat Fregate::getDistanceAttaque() const
{
    return 4;
}
