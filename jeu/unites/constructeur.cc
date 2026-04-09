#include "constructeur.hh"

Constructeur::Constructeur(Faction faction, usint pointsVie, usint nbMuntions, usint nbProvisions):
    Unite(faction, pointsVie, nbMuntions, nbProvisions),
    Infanterie(faction, pointsVie, nbMuntions, nbProvisions)
{}

std::string Constructeur::getNom() const
{
    return Infanterie::getNom() + " - Constructeur";
}
