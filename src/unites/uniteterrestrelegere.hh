#pragma once

#include "unitelegere.hh"
#include "uniteterrestre.hh"

class UniteTerrestreLegere: public UniteLegere, public UniteTerrestre {
public:
    UniteTerrestreLegere(usint pointsVie, usint nbMunitions,
                         usint nbProvisions);
};
