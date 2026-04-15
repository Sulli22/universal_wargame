#include "jeu.hh"

Jeu::Jeu(unsigned int idGuerre, Faction faction1, Faction faction2):
    _plateau(idGuerre), _faction1(faction1), _faction2(faction2)
{
    if (_faction1 == _faction2)
        throw std::invalid_argument("Erreur : les factions doivent etre adverses");
}

void Jeu::jouerTour()
{
    // actions cases

    // Faction 1

    // Faction 2
}

void Jeu::jouerPartie()
{
    // TODO
    /*
     * while() {
     *  jouerTour();
     * }
     */
}
