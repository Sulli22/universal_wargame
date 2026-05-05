#include "unitelegere.hh"

UniteLegere::UniteLegere(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                         uint16_t nbProvisions,
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
