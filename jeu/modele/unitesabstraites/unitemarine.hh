#pragma once

#include "unitelourde.hh"

class UniteMarine: public UniteLourde {
public:
    UniteMarine(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                uint16_t nbProvisions, uint16_t pointsBouclier,
                Visibilite visibilite = Visibilite::totale);
};

