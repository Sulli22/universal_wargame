#include "uniteterrestrelegere.hh"

UniteTerrestreLegere::UniteTerrestreLegere(Faction faction, stat pointsVie,
                                           stat nbMunitions,
                                           stat nbProvisions,
                                           Visibilite visibilite):
    UniteLegere(faction, pointsVie, nbMunitions, nbProvisions, visibilite),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
