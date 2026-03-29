#pragma once

#include "unitelourde.hh"

class UniteTerrestreLourde : public UniteLourde {
public:
    UniteTerrestreLourde(usint pointsVie, usint nbMunitions, usint nbProvisions,
                         usint pointsBouclier);
};
