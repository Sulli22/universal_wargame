#include "charassaut.hh"

CharAssaut::CharAssaut(Faction faction, Stat pointsVie, Stat nbMunitions,
                       Stat nbProvisions, Stat pointsBouclier):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLourde(faction, pointsVie, nbMunitions, nbProvisions,
                           pointsBouclier)
{}

std::string CharAssaut::getNom() const
{
    return "Char d'assaut";
}

Stat CharAssaut::getPointsAttaqueLegere() const
{
    return 8;
}

Stat CharAssaut::getPointsAttaqueLourde() const
{
    return 18;
}

Stat CharAssaut::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    Stat capacite = 2;
    Stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capacite);
}

Stat CharAssaut::getDistanceAttaque() const
{
    return 3;
}
