#pragma once

#include "unite.hh"

class UniteTerrestre : virtual public Unite {
public:
    UniteTerrestre(Faction faction, stat pointsVie, stat nbMunitions,
                   stat nbProvisions,
                   Visibilite visibilite = Visibilite::totale);
};
