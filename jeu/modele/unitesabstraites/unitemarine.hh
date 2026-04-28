#pragma once

#include "unitelourde.hh"

class UniteMarine: public UniteLourde {
public:
    UniteMarine(Faction faction, usint pointsVie, usint nbMunitions,
                usint nbProvisions, usint pointsBouclier,
                Visibilite visibilite = Visibilite::totale);
};

