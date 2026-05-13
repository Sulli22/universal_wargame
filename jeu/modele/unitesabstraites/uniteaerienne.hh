#pragma once

#include "unitelourde.hh"

class UniteAerienne: public UniteLourde {
public:
    UniteAerienne(Faction faction, Stat pointsVie, Stat nbMunitions,
                  Stat nbProvisions, Stat pointsBouclier,
                  Visibilite visibilite = Visibilite::totale);
};

