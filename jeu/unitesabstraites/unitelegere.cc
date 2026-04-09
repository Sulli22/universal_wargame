#include "unitelegere.hh"

UniteLegere::UniteLegere(Faction faction, usint pointsVie, usint nbMunitions,
                         usint nbProvisions):
    Unite(faction, pointsVie, nbMunitions, nbProvisions)
{}

bool UniteLegere::estLegere() const
{
    return true;
}

void UniteLegere::sortieFlux(std::ostream &os) const
{
    Unite::sortieFlux(os);
    os << " taille=" << getTaille();
}
