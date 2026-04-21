#pragma once

#include "carte.hh"

class Model {
public:
    Model(unsigned int idGuerre,
        Faction faction1 = Faction::bleue,
        Faction faction2 = Faction::rouge);

    Faction getFaction1() const;
    Faction getFaction2() const;
    Faction getFactionAttaquante() const;
    Faction getFactionAttaquee() const;

    bool factionEstPerdante(Faction faction) const;
    bool partieFinie() const;
    Faction factionVictorieuse() const;

    void changementJoueur();
    std::vector<Case *> getCasesFactionAttaquante() const;
    void selectionnerCase(const Position &pos);
    Unite *getUniteSelectionee() const;
    usint getNbActionsPossibles() const;
    bool uniteSelectioneeAJoue() const;
    void effectuerAction(usint indAction);

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

    Case *_caseSelectionnee;
    usint _indUniteSelectionnee;

    std::set<Unite *> _unitesAyantJoue;
};
