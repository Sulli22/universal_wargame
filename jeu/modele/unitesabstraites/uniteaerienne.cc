#include "uniteaerienne.hh"

UniteAerienne::UniteAerienne(Faction faction, Stat pointsVie,
                             Stat nbMunitions, Stat nbProvisions,
                             Stat pointsBouclier, Visibilite visibilite):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                visibilite)
{}
