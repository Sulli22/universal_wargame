#pragma once

#include "unitelegere.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLegere: public UniteLegere, public UniteTerrestre {
public:
    UniteTerrestreLegere(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                         uint16_t nbProvisions,
                         Visibilite visibilite = Visibilite::totale);
};
