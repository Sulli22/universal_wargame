#include "uniteterrestrelegere.hh"

UniteTerrestreLegere::UniteTerrestreLegere(Faction faction, uint16_t pointsVie,
                                           uint16_t nbMunitions,
                                           uint16_t nbProvisions,
                                           Visibilite visibilite):
    UniteLegere(faction, pointsVie, nbMunitions, nbProvisions, visibilite),
    UniteTerrestre(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
