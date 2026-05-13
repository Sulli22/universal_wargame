#include "unitemarine.hh"

UniteMarine::UniteMarine(Faction faction, Stat pointsVie, Stat nbMunitions,
                         Stat nbProvisions, Stat pointsBouclier,
                         Visibilite visibilite):
    UniteLourde(faction, pointsVie, nbMunitions, nbProvisions, pointsBouclier,
                  visibilite)
{}
