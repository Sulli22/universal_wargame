#pragma once

#include "unite.hh"

class UniteTerrestre : virtual public Unite {
public:
    UniteTerrestre(usint pointsVie, usint nbMunitions, usint nbProvisions);
};
