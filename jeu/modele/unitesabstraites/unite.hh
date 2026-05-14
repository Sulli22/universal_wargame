#pragma once

#include <ostream>
#include <vector>

using Stat = unsigned int;          // type statistique (points, nb munitions, ...)
using IndiceAction = unsigned int;  // type indice pour actions possibles

enum class Faction { rouge, bleue, neutre };

class Unite {
public:
    enum class Visibilite { nulle, partielle, totale };

    Unite(Faction faction, Stat pointsVie, Stat nbMunitions,
          Stat nbProvisions, Visibilite visibilite = Visibilite::totale);
    virtual ~Unite() =default;

// getters
    Faction getFaction() const;
    Stat getPointsVie() const;
    Stat getNbMunitions() const;
    Stat getNbProvisions() const;
    Visibilite getVisibilite() const;
    Stat getMaxPointsVie() const;
    Stat getMaxNbMunitions() const;
    Stat getMaxNbProvisions() const;

// setter
    void setVisibilite(Visibilite nvVisibilite);

// recharges (effets des constructions)
    void regagnerVie();
    void rechargerMunitions();
    virtual void rechargerProvisions();

// stats virtuelles
    virtual std::string getNom() const =0;
    virtual Stat getPointsAttaqueLegere() const =0;
    virtual Stat getPointsAttaqueLourde() const =0;
    virtual Stat getCapaciteDeplacement() const =0;
    virtual Stat getDistanceAttaque() const =0;
    virtual std::vector<IndiceAction> getIndicesActionsPossibles() const;

// méthodes pour tests
    virtual bool estLegere() const =0;
    bool estOperationnelle() const;

// méthodes pour jeu
    virtual void prendreDegats(Stat degats);
    void attaquerUnite(Unite *unite);
    void utiliserProvisions(Stat nbProvisions);

// sortie flux
    virtual void sortieFlux(std::ostream &os) const;

private:
// méthode pour sortie flux
    std::string getChaineVisibilite() const;

// attributs
    Faction _faction;
    Stat _pointsVie;
    Stat _nbMunitions;
    Stat _nbProvisions;
    Visibilite _visibilite;

    const Stat _MAX_POINTS_VIE;
    const Stat _MAX_NB_MUNITIONS;
    const Stat _MAX_NB_PROVISIONS;

// constante pour les recharges
    static constexpr float _MULT_RECHARGE = 0.2f;    // i.e. "un cinquième"
};
