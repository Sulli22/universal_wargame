#pragma once

#include <ostream>
#include <vector>

using stat = unsigned int;          // type statistique (points, nb munitions, ...)
using indiceAction = unsigned int;  // type indice pour actions possibles

enum class Faction { rouge, bleue, neutre };

class Unite {
public:
    enum class Visibilite { nulle, partielle, totale };

    Unite(Faction faction, stat pointsVie, stat nbMunitions,
          stat nbProvisions, Visibilite visibilite = Visibilite::totale);
    virtual ~Unite() =default;

// getters
    Faction getFaction() const;
    stat getPointsVie() const;
    stat getNbMunitions() const;
    stat getNbProvisions() const;
    Visibilite getVisibilite() const;
    stat getMaxPointsVie() const;
    stat getMaxNbMunitions() const;
    stat getMaxNbProvisions() const;

// recharges (effets des constructions)
    void regagnerVie();
    void rechargerMunitions();
    virtual void rechargerProvisions();

// stats virtuelles
    virtual std::string getNom() const =0;
    virtual stat getPointsAttaqueLegere() const =0;
    virtual stat getPointsAttaqueLourde() const =0;
    virtual stat getCapaciteDeplacement() const =0;
    virtual stat getDistanceAttaque() const =0;
    virtual std::vector<indiceAction> getIndicesActionsPossibles() const;

// méthodes pour tests
    virtual bool estLegere() const =0;
    bool estOperationnelle() const;

// méthodes pour jeu
    virtual void prendreDegats(stat degats);
    void attaquerUnite(Unite *unite);
    void utiliserProvisions(stat nbProvisions);
    void setVisibilite(Visibilite nvVisibilite);

// sortie flux
    virtual void sortieFlux(std::ostream &os) const;

private:
// méthode pour sortie flux
    std::string getChaineVisibilite() const;

// attributs
    Faction _faction;
    stat _pointsVie;
    stat _nbMunitions;
    stat _nbProvisions;
    Visibilite _visibilite;

    const stat _MAX_POINTS_VIE;
    const stat _MAX_NB_MUNITIONS;
    const stat _MAX_NB_PROVISIONS;

// constante pour les recharges
    static constexpr float _MULT_RECHARGE = 0.2f;    // i.e. "un cinquième"
};
