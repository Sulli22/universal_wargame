#pragma once

#include "unite.hh"

class UniteTerrestre : virtual public Unite {
public:
    UniteTerrestre(Faction faction, usint pointsVie, usint nbMunitions,
                   usint nbProvisions,
                   Visibilite visibilite = Visibilite::totale);
};
