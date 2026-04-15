#pragma once

#include "carte.hh"

class Jeu {
public:
    Jeu(unsigned int idGuerre,
        Faction faction1 = Faction::bleu,
        Faction faction2 = Faction::rouge);

    void jouerTour();
    void jouerPartie();

private:
    Carte _plateau;
    Faction _faction1;
    Faction _faction2;
};

