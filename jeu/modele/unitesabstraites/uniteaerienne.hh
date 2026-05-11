#pragma once

#include "unitelourde.hh"

class UniteAerienne: public UniteLourde {
public:
    UniteAerienne(Faction faction, stat pointsVie, stat nbMunitions,
                  stat nbProvisions, stat pointsBouclier,
                  Visibilite visibilite = Visibilite::totale);
};

