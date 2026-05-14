#include "uniteterrestrelourde.hh"

UniteTerrestreLourde::UniteTerrestreLourde(Faction faction, Stat pointsVie,
                                           Stat nbMunitions,
                                           Stat nbProvisions,
                                           Stat pointsBouclier,
                                           Visibilite visibilite):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                  visibilite),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
