#pragma once

#include "unitelegere.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLegere: public UniteLegere, public UniteTerrestre {
public:
    UniteTerrestreLegere(Faction faction, usint pointsVie, usint nbMunitions,
                         usint nbProvisions,
                         Visibilite visibilite = Visibilite::totale);
};
