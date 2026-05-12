#include "infanterie.hh"

Infanterie::Infanterie(Faction faction, stat pointsVie, stat nbMunitions,
                       stat nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Infanterie::getNom() const
{
    return "Infanterie";
}

stat Infanterie::getPointsAttaqueLegere() const
{
    return 10;
}

stat Infanterie::getPointsAttaqueLourde() const
{
    return 12;
}

stat Infanterie::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    stat capaciteReelle = 4;
    stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capaciteReelle);
}

stat Infanterie::getDistanceAttaque() const
{
    return 1;
}

stat Infanterie::getTaille() const
{
    return 1;
}
