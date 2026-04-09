#pragma once

#include "unitelourde.hh"

class UniteAerienne: public UniteLourde {
public:
    UniteAerienne(Faction faction, usint pointsVie, usint nbMunitions,
                  usint nbProvisions, usint pointsBouclier,
                  Visibilite visibilite = Visibilite::totale);
};

