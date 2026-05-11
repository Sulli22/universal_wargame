#pragma once

#include "unitelourde.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLourde: public UniteLourde, public UniteTerrestre {
public:
    UniteTerrestreLourde(Faction faction, stat pointsVie, stat nbMunitions,
                         stat nbProvisions, stat pointsBouclier,
                         Visibilite visibilite = Visibilite::totale);
};
