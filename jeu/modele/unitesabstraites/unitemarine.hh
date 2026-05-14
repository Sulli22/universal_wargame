#pragma once

#include "unitelourde.hh"

class UniteMarine: public UniteLourde {
public:
    UniteMarine(Faction faction, Stat pointsVie, Stat nbMunitions,
                Stat nbProvisions, Stat pointsBouclier,
                Visibilite visibilite = Visibilite::totale);
};

