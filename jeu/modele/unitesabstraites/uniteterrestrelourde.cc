#include "uniteterrestrelourde.hh"

UniteTerrestreLourde::UniteTerrestreLourde(Faction faction, stat pointsVie,
                                           stat nbMunitions,
                                           stat nbProvisions,
                                           stat pointsBouclier,
                                           Visibilite visibilite):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                  visibilite),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
