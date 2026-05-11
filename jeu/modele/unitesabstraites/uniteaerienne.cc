#include "uniteaerienne.hh"

UniteAerienne::UniteAerienne(Faction faction, stat pointsVie,
                             stat nbMunitions, stat nbProvisions,
                             stat pointsBouclier, Visibilite visibilite):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                visibilite)
{}
