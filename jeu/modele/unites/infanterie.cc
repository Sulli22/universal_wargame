#include "infanterie.hh"

Infanterie::Infanterie(Faction faction, Stat pointsVie, Stat nbMunitions,
                       Stat nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Infanterie::getNom() const
{
    return "Infanterie";
}

Stat Infanterie::getPointsAttaqueLegere() const
{
    return 10;
}

Stat Infanterie::getPointsAttaqueLourde() const
{
    return 12;
}

Stat Infanterie::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    Stat capacite = 4;
    Stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capacite);
}

Stat Infanterie::getDistanceAttaque() const
{
    return 1;
}

Stat Infanterie::getTaille() const
{
    return 1;
}
