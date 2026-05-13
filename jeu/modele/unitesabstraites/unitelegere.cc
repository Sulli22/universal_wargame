#include "unitelegere.hh"

UniteLegere::UniteLegere(Faction faction, Stat pointsVie, Stat nbMunitions,
                         Stat nbProvisions,
                         Visibilite visibilite):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
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
