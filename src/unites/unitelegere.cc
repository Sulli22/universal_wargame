#include "unitelegere.hh"

UniteLegere::UniteLegere(unsigned int pointsVie,
                         unsigned int nbMunitions)
    : Unite(pointsVie, nbMunitions)
{}

bool UniteLegere::estLegere() const
{
    return true;
}
