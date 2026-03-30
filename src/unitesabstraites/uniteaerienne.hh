#pragma once

#include "unitelourde.hh"

class UniteAerienne: public UniteLourde {
public:
    UniteAerienne(usint pointsVie, usint nbMunitions, usint nbProvisions,
                  usint pointsBouclier);
};

