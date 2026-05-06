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

    Faction getFaction1() const;
    Faction getFaction2() const;
    Faction getFactionAttaquante() const;
    Faction getFactionAttaquee() const;
    Case *getCaseSelectionnee() const;
    Case *getCaseCible() const;

    // plateau
    bool positionValidePlateau(const Position &pos) const;
    std::size_t getLargeurPlateau() const;
    std::size_t getHauteurPlateau() const;
    Case *accesCasePlateau(const Position &pos) const;

    bool partieFinie() const;
    Faction factionVictorieuse() const;
    void changementJoueur();
    std::vector<Case *> getCasesConcernees() const;
    bool estConcernee(Case *c) const;
    std::vector<Case *> getChemin() const;
    void selectionnerCase(const Position &pos);
    void annulerSelections();
    Unite *getUniteSelectionee() const;
    uint16_t getNbActionsPossibles() const;
    void choixAction(uint16_t indAction);
    void effectuerAction();
    uint16_t getNbConstructionsPossibles() const;
    void choixConstruction(uint16_t indConstruction);

// sortie flux
    void sortieFlux(std::ostream &os) const;

private:
    void setEtat(etat nvEtat);
    bool factionEstPerdante(Faction faction) const;
    bool uniteSelectioneeAJoue() const;

    static std::string factionToString(Faction faction);
    static std::vector<Case *> keysFromMap(const std::map<Case *, uint16_t> &map);

// attributs
    Carte _plateau;

    const Faction _faction1;
    const Faction _faction2;
    const uint16_t _seuilDefaiteFaction1;
    const uint16_t _seuilDefaiteFaction2;
    Faction _factionAttaquante;
    Faction _factionAttaquee;

    Case *_caseSelectionnee;
    uint16_t _indUniteSelectionnee;
    Case *_caseCible;
    std::unique_ptr<Construction> _aConstruire;
    std::set<Unite *> _unitesAyantJoue;
    etat _etat;
};
