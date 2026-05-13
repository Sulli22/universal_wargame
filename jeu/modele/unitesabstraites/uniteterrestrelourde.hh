#pragma once

#include "unitelourde.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLourde: public UniteLourde, public UniteTerrestre {
public:
    UniteTerrestreLourde(Faction faction, Stat pointsVie, Stat nbMunitions,
                         Stat nbProvisions, Stat pointsBouclier,
                         Visibilite visibilite = Visibilite::totale);
};
