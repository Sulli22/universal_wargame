#include "uniteterrestrelourde.hh"

UniteTerrestreLourde::UniteTerrestreLourde(usint pointsVie, usint nbMunitions,
                                           usint nbProvisions,
                                           usint pointsBouclier):
    UniteLourde(pointsVie, nbMunitions, nbProvisions, pointsBouclier),
    UniteTerrestre(pointsVie, nbMunitions, nbProvisions)
{}
