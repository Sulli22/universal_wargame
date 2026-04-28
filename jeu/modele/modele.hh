#pragma once

#include "carte.hh"
#include "construction.hh"

class Modele {
public:
    enum class etat {
        selection,      // selection unite
        deplacement,    // selection case où se déplacer parmi les atteignables
        attaque,        // selection case où attaquer parmi les attaquables
        construction    // selection case où construire parmi les voisines
    };

    Modele(unsigned int idGuerre,
        Faction faction1 = Faction::bleue, Faction faction2 = Faction::rouge);

    const Carte& getPlateau() const;
    Faction getFaction1() const;
    Faction getFaction2() const;
    Faction getFactionAttaquante() const;
    Faction getFactionAttaquee() const;
    Case *getCaseSelectionnee() const;
    Case *getCaseCible() const;

    bool partieFinie() const;
    Faction factionVictorieuse() const;
    void changementJoueur();
    std::vector<Case *> getCasesConcernees() const;
    std::vector<Case *> getChemin() const;
    void selectionnerCase(const Position &pos);
    void annulerSelections();
    Unite *getUniteSelectionee() const;
    usint getNbActionsPossibles() const;
    void choixAction(usint indAction);
    void effectuerAction();
    usint getNbConstructionsPossibles() const;
    void choixConstruction(usint indConstruction);

// sortie flux
    void sortieFlux(std::ostream &os) const;

private:
    void setEtat(etat nvEtat);
    bool factionEstPerdante(Faction faction) const;
    bool uniteSelectioneeAJoue() const;

    static std::string factionToString(Faction faction);
    static std::vector<Case *> keysFromMap(const std::map<Case *, usint> &map);

// attributs
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
    std::unique_ptr<Construction> _aConstruire;
    std::set<Unite *> _unitesAyantJoue;
    etat _etat;
};
