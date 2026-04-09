#include "uniteterrestrelourde.hh"

UniteTerrestreLourde::UniteTerrestreLourde(Faction faction, usint pointsVie, usint nbMunitions,
                                           usint nbProvisions,
                                           usint pointsBouclier):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions)
{}
