#include "uniteaerienne.hh"

UniteAerienne::UniteAerienne(Faction faction, usint pointsVie,
                             usint nbMunitions, usint nbProvisions,
                             usint pointsBouclier):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier)
{}
