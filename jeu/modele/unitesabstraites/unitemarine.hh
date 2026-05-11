#pragma once

#include "unitelourde.hh"

class UniteMarine: public UniteLourde {
public:
    UniteMarine(Faction faction, stat pointsVie, stat nbMunitions,
                stat nbProvisions, stat pointsBouclier,
                Visibilite visibilite = Visibilite::totale);
};

