#pragma once

#include "unitelourde.hh"

class UniteAerienne: public UniteLourde {
public:
    UniteAerienne(unsigned int pointsVie,
                  unsigned int nbMunitions,
                  unsigned int pointsBouclier);
};

