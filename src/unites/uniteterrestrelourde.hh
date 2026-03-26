#pragma once

#include "unitelourde.hh"

class UniteTerrestreLourde : public UniteLourde {
public:
    UniteTerrestreLourde(unsigned int pointsVie,
                         unsigned int nbMunitions,
                         unsigned int pointsBouclier);
};
