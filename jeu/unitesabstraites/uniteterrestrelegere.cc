#include "uniteterrestrelegere.hh"

UniteTerrestreLegere::UniteTerrestreLegere(Faction faction, usint pointsVie,
                                           usint nbMunitions,
                                           usint nbProvisions,
                                           Visibilite visibilite):
    UniteLegere(faction, pointsVie, nbMunitions, nbProvisions, visibilite),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
