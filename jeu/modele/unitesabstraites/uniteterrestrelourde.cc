#include "uniteterrestrelourde.hh"

UniteTerrestreLourde::UniteTerrestreLourde(Faction faction, uint16_t pointsVie,
                                           uint16_t nbMunitions,
                                           uint16_t nbProvisions,
                                           uint16_t pointsBouclier,
                                           Visibilite visibilite):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                  visibilite),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
