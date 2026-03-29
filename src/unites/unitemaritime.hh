#pragma once

#include "unitelourde.hh"

class UniteMaritime: public UniteLourde {
public:
    UniteMaritime(usint pointsVie, usint nbMunitions, usint nbProvisions,
                  usint pointsBouclier);
};

