#include "uniteaerienne.hh"

UniteAerienne::UniteAerienne(Faction faction, usint pointsVie,
                             usint nbMunitions, usint nbProvisions,
                             usint pointsBouclier, Visibilite visibilite):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                visibilite)
{}
