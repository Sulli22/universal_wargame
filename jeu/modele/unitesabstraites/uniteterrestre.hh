#pragma once

#include "unite.hh"

class UniteTerrestre : virtual public Unite {
public:
    UniteTerrestre(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                   uint16_t nbProvisions,
                   Visibilite visibilite = Visibilite::totale);
};
