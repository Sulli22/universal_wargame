#pragma once

#include "unitelourde.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLourde: public UniteLourde, public UniteTerrestre {
public:
    UniteTerrestreLourde(Faction faction, usint pointsVie, usint nbMunitions,
                         usint nbProvisions, usint pointsBouclier,
                         Visibilite visibilite = Visibilite::totale);
};
