#include "uniteterrestre.hh"

UniteTerrestre::UniteTerrestre(Faction faction, uint16_t pointsVie,
                               uint16_t nbMunitions, uint16_t nbProvisions,
                               Visibilite visibilite):
    Unite(faction, pointsVie, nbMunitions, nbProvisions, visibilite)
{}
