#pragma once

#include "unitelegere.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLegere: public UniteLegere, public UniteTerrestre {
public:
    UniteTerrestreLegere(Faction faction, Stat pointsVie, Stat nbMunitions,
                         Stat nbProvisions,
                         Visibilite visibilite = Visibilite::totale);
};
