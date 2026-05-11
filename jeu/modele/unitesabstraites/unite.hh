#pragma once

#include <ostream>
#include <set>

using stat = unsigned int;
using indiceAction = unsigned int;

enum class Faction { rouge, bleue, neutre };

class Unite {
public:
    enum class Visibilite { nulle, partielle, totale };

    Unite(Faction faction, stat pointsVie, stat nbMunitions,
          stat nbProvisions, Visibilite visibilite = Visibilite::totale);
    virtual ~Unite() =default;

    Faction getFaction() const;
    stat getPointsVie() const;
    stat getNbMunitions() const;
    stat getNbProvisions() const;
    Visibilite getVisibilite() const;
    stat getMaxPointsVie() const;
    stat getMaxNbMunitions() const;
    stat getMaxNbProvisions() const;

    void regagnerViePartielle();
    void rechargerMunitions();
    void rechargerProvisions();

    virtual std::string getNom() const =0;
    virtual stat getPointsAttaqueLegere() const =0;
    virtual stat getPointsAttaqueLourde() const =0;
    virtual stat getCapaciteDeplacement() const =0;
    virtual stat getDistanceAttaque() const =0;
    virtual std::set<indiceAction> getIndicesActionsPossibles() const;

    virtual bool estLegere() const =0;
    bool estOperationnelle() const;
    std::string getChaineVisibilite() const;

    virtual void prendreDegats(stat degats);
    void attaquerUnite(Unite *unite);
    void utiliserProvisions(stat nbProvisions);
    void setVisibilite(Visibilite nvVisibilite);

// sortie flux
    virtual void sortieFlux(std::ostream &os) const;

private:
    Faction _faction;

    stat _pointsVie;
    stat _nbMunitions;
    stat _nbProvisions;

    Visibilite _visibilite;

    stat const _MAX_POINTS_VIE;
    stat const _MAX_NB_MUNITIONS;
    stat const _MAX_NB_PROVISIONS;
};
