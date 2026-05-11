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

// getters
    Faction getFactionAttaquante() const;
    Case *getCaseSelectionnee() const;
    Case *getCaseCible() const;

// plateau
    bool positionValidePlateau(const Position &pos) const;
    std::size_t getLargeurPlateau() const;
    std::size_t getHauteurPlateau() const;
    Case *accesCasePlateau(const Position &pos) const;

// fin de partie
    bool partieFinie() const;
    Faction getFactionVictorieuse() const;

// changement de joueur (permute factions attaquante-attaquee)
    void changerJoueur();

// cases concernees
    std::vector<Case *> getCasesConcernees() const;
    bool estConcernee(Case *c) const;

// chemin
    bool cheminExiste() const;
    std::vector<Case *> getChemin() const;

// selection
    void selectionnerCase(const Position &pos);
    void annulerSelections();
    Unite *getUniteSelectionee() const;

// constructions
    uint16_t getNbConstructionsPossibles() const;
    void choixConstruction(uint16_t indConstruction);

// actions
    uint16_t getNbActionsPossibles() const;
    void choixAction(uint16_t indAction);
    bool actionValidable() const;
    void effectuerAction();

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
    etat _etat;

    const Faction _faction1;
    const Faction _faction2;
    Faction _factionAttaquante;
    Faction _factionAttaquee;

    const uint16_t _seuilDefaiteFaction1;
    const uint16_t _seuilDefaiteFaction2;

    Case *_caseSelectionnee;
    uint16_t _indUniteSelectionnee;
    Case *_caseCible;
    std::unique_ptr<Construction> _aConstruire;
    std::set<Unite *> _unitesAyantJoue;
};
