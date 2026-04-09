#include "uniteterrestrelegere.hh"

UniteTerrestreLegere::UniteTerrestreLegere(Faction faction, usint pointsVie,
                                           usint nbMunitions, usint nbProvisions):
    UniteLegere(faction, pointsVie, nbMunitions, nbProvisions),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions)
{}
