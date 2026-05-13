#include "uniteterrestrelegere.hh"

UniteTerrestreLegere::UniteTerrestreLegere(Faction faction, Stat pointsVie,
                                           Stat nbMunitions,
                                           Stat nbProvisions,
                                           Visibilite visibilite):
    UniteLegere(faction, pointsVie, nbMunitions, nbProvisions, visibilite),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
