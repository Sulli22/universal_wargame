#include "artillerie.hh"

Artillerie::Artillerie(Faction faction, stat pointsVie, stat nbMunitions,
                       stat nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestreLegere(faction, pointsVie, nbMunitions, nbProvisions)
{}

std::string Artillerie::getNom() const
{
    return "Artillerie";
}

stat Artillerie::getPointsAttaqueLegere() const
{
    return 10;
}

stat Artillerie::getPointsAttaqueLourde() const
{
    return 18;
}

stat Artillerie::getCapaciteDeplacement() const
{
    stat capaciteReelle = 3;
    stat capaciteMin = Unite::getCapaciteDeplacement();
    return std::min(capaciteMin, capaciteReelle);
}

stat Artillerie::getDistanceAttaque() const
{
    return 3;
}

stat Artillerie::getTaille() const
{
    return 2;
}
