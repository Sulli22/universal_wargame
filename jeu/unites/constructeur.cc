#include "constructeur.hh"

Constructeur::Constructeur(usint pointsVie, usint nbMuntions, usint nbProvisions):
    Unite(pointsVie, nbMuntions, nbProvisions),
    Infanterie(pointsVie, nbMuntions, nbProvisions)
{}

std::string Constructeur::getNom() const
{
    return Infanterie::getNom() + " - Constructeur";
}
