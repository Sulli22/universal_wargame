#pragma once

#include <ostream>

using usint = unsigned short int;

enum class Faction { rouge, bleue, neutre };

class Unite {
public:
    enum class Visibilite { nulle, partielle, totale };

    Unite(Faction faction, usint pointsVie, usint nbMunitions,
          usint nbProvisions, Visibilite visibilite = Visibilite::totale);
    virtual ~Unite() =default;

    Faction getFaction() const;

    usint getPointsVie() const;
    usint getNbMunitions() const;
    usint getNbProvisions() const;

    Visibilite getVisibilite() const;

    usint getMaxPointsVie() const;
    usint getMaxNbMunitions() const;
    usint getMaxNbProvisions() const;

    void regagnerViePartielle();
    void rechargerMunitions();
    void rechargerProvisions();

    virtual std::string getNom() const =0;
    virtual usint getPointsAttaqueLegere() const =0;
    virtual usint getPointsAttaqueLourde() const =0;
    virtual usint getCapaciteDeplacement() const =0;
    virtual usint getDistanceAttaque() const =0;

    virtual bool estLegere() const =0;
    bool estOperationnelle() const;
    std::string getChaineVisibilite() const;
    virtual void sortieFlux(std::ostream &os) const;

    virtual void prendreDegats(usint degats);
    void attaquerUnite(Unite *unite);
    void utiliserProvisions(usint nbProvisions);
    void setVisibilite(Visibilite nvVisibilite);

private:
    Faction _faction;

    usint _pointsVie;
    usint _nbMunitions;
    usint _nbProvisions;

    Visibilite _visibilite;

    usint const _MAX_POINTS_VIE;
    usint const _MAX_NB_MUNITIONS;
    usint const _MAX_NB_PROVISIONS;
};
