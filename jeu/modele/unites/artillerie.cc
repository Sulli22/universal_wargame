#include "artillerie.hh"

Artillerie::Artillerie(Faction faction, Stat pointsVie, Stat nbMunitions,
                       Stat nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Artillerie::getNom() const
{
    return "Artillerie";
}

Stat Artillerie::getPointsAttaqueLegere() const
{
    return 10;
}

Stat Artillerie::getPointsAttaqueLourde() const
{
    return 18;
}

Stat Artillerie::getCapaciteDeplacement() const
{
    // réduit la capacité de déplacement au nb de provisions
    // si celui ci est insufisant pour un déplacement complet
    Stat capacite = 3;
    Stat capaciteMin = getNbProvisions();
    return std::min(capaciteMin, capacite);
}

Stat Artillerie::getDistanceAttaque() const
{
    return 3;
}

Stat Artillerie::getTaille() const
{
    return 2;
}
