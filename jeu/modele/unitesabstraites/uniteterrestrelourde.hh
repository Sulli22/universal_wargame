#pragma once

#include "unitelourde.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLourde: public UniteLourde, public UniteTerrestre {
public:
    UniteTerrestreLourde(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                         uint16_t nbProvisions, uint16_t pointsBouclier,
                         Visibilite visibilite = Visibilite::totale);
};
