#pragma once

#include "carte.hh"

class Model {
public:
    Model(unsigned int idGuerre,
        Faction faction1 = Faction::bleue,
        Faction faction2 = Faction::rouge);

    bool factionEstPerdante(Faction faction) const;
    bool partieFinie() const;
    Faction factionVictorieuse() const;

    void changementJoueur();

    void sortieFlux(std::ostream &os) const;

private:
    static std::string factionToString(Faction faction);

private:
    Carte _plateau;

    const Faction _faction1;
    const Faction _faction2;
    const usint _seuilDefaiteFaction1;
    const usint _seuilDefaiteFaction2;

    Faction _factionAttaquante;
    Faction _factionAttaquee;
};
