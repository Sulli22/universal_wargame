#pragma once

#include "unite.hh"

class UniteTerrestre : virtual public Unite {
public:
    UniteTerrestre(Faction faction, Stat pointsVie, Stat nbMunitions,
                   Stat nbProvisions, Visibilite visibilite);
};
