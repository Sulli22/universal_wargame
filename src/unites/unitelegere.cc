#include "unitelegere.hh"

UniteLegere::UniteLegere(usint pointsVie, usint nbMunitions) :
    Unite(pointsVie, nbMunitions)
{}

bool UniteLegere::estLegere() const
{
    return true;
}
