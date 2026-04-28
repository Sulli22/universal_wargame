#include "uniteterrestrelourde.hh"

UniteTerrestreLourde::UniteTerrestreLourde(Faction faction, usint pointsVie,
                                           usint nbMunitions,
                                           usint nbProvisions,
                                           usint pointsBouclier,
                                           Visibilite visibilite):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                  visibilite),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
