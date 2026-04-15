#pragma once

#include "carte.hh"

class Jeu {
public:
    Jeu(unsigned int idGuerre,
        Faction faction1 = Faction::bleu,
        Faction faction2 = Faction::rouge);

    bool factionAPerdue(Faction faction) const;
    bool partieFinie() const;
    Faction factionGagante() const;

    void jouerTour();
    void jouerPartie();

private:
    Carte _plateau;

    const Faction _faction1;
    const Faction _faction2;
    const usint _seuilDefaiteFaction1;
    const usint _seuilDefaiteFaction2;
};

