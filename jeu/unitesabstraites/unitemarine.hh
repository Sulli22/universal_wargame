#pragma once

#include "unitelourde.hh"

class UniteMarine: public UniteLourde {
public:
    UniteMarine(usint pointsVie, usint nbMunitions, usint nbProvisions,
                  usint pointsBouclier);
};

