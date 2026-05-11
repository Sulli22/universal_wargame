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
    stat capaciteReelle = 3;
    stat capaciteMin = Unite::getCapaciteDeplacement();
    return std::min(capaciteMin, capaciteReelle);
}

stat Fregate::getDistanceAttaque() const
{
    return 5;
}
