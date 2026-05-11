#pragma once

#include "unitelegere.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLegere: public UniteLegere, public UniteTerrestre {
public:
    UniteTerrestreLegere(Faction faction, stat pointsVie, stat nbMunitions,
                         stat nbProvisions,
                         Visibilite visibilite = Visibilite::totale);
};
