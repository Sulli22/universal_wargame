#include "genie.hh"

Genie::Genie(Faction faction, usint pointsVie, usint nbMuntions, usint nbProvisions):
    Unite(faction, pointsVie, nbMuntions, nbProvisions),
    Infanterie(faction, pointsVie, nbMuntions, nbProvisions)
{}

std::string Genie::getNom() const
{
    return Infanterie::getNom() + " - Constructeur";
}
