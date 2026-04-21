#pragma once

#include "carte.hh"

class Model {
public:
    enum class etat {
        selection,      // selection unite
        deplacement,    // selection case où se déplacer parmi les atteignables
        attaque,        // selection case où attaquer parmi les attaquables
        construction    // selection case où construire parmi les voisines
    };

    Model(unsigned int idGuerre,
        Faction faction1 = Faction::bleue, Faction faction2 = Faction::rouge);

    Faction getFaction1() const;
    Faction getFaction2() const;
    Faction getFactionAttaquante() const;
    Faction getFactionAttaquee() const;

    Case *getCaseSelectionnee() const;
    Case *getCaseCible() const;

    void setEtat(etat nvEtat);

    bool factionEstPerdante(Faction faction) const;
    bool partieFinie() const;
    Faction factionVictorieuse() const;

    void changementJoueur();
    std::vector<Case *> getCasesConcernees() const;
    void selectionnerCase(const Position &pos);
    Unite *getUniteSelectionee() const;
    usint getNbActionsPossibles() const;
    bool uniteSelectioneeAJoue() const;
    void choixAction(usint indAction);
    void effectuerAction();

    void sortieFlux(std::ostream &os) const;

private:
    static std::string factionToString(Faction faction);
    static std::vector<Case *> keysFromMap(const std::map<Case *, usint> &map);


    Carte _plateau;

    const Faction _faction1;
    const Faction _faction2;
    const usint _seuilDefaiteFaction1;
    const usint _seuilDefaiteFaction2;

    Faction _factionAttaquante;
    Faction _factionAttaquee;

    Case *_caseSelectionnee;
    usint _indUniteSelectionnee;
    Case *_caseCible;

    std::set<Unite *> _unitesAyantJoue;

    etat _etat;
};
