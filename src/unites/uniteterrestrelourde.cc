#include "uniteterrestrelourde.hh"

UniteTerrestreLourde::UniteTerrestreLourde(usint pointsVie, usint nbMunitions,
                                           usint nbProvisions,
                                           usint pointsBouclier) :
    Unite(pointsVie, nbMunitions, nbProvisions),
    UniteLourde(pointsVie, nbMunitions, nbProvisions, pointsBouclier),
    UniteTerrestre(pointsVie, nbMunitions, nbProvisions)
{}
