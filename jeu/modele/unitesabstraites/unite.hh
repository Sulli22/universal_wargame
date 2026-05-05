#pragma once

#include <ostream>
#include <cstdint>

enum class Faction { rouge, bleue, neutre };

class Unite {
public:
    enum class Visibilite { nulle, partielle, totale };

    Unite(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
          uint16_t nbProvisions, Visibilite visibilite = Visibilite::totale);
    virtual ~Unite() =default;

    Faction getFaction() const;

    uint16_t getPointsVie() const;
    uint16_t getNbMunitions() const;
    uint16_t getNbProvisions() const;

    Visibilite getVisibilite() const;

    uint16_t getMaxPointsVie() const;
    uint16_t getMaxNbMunitions() const;
    uint16_t getMaxNbProvisions() const;

    void regagnerViePartielle();
    void rechargerMunitions();
    void rechargerProvisions();

    virtual std::string getNom() const =0;
    virtual uint16_t getPointsAttaqueLegere() const =0;
    virtual uint16_t getPointsAttaqueLourde() const =0;
    virtual uint16_t getCapaciteDeplacement() const =0;
    virtual uint16_t getDistanceAttaque() const =0;
    virtual uint16_t getNbActionsPossibles() const;

    virtual bool estLegere() const =0;
    bool estOperationnelle() const;
    std::string getChaineVisibilite() const;

    virtual void prendreDegats(uint16_t degats);
    void attaquerUnite(Unite *unite);
    void utiliserProvisions(uint16_t nbProvisions);
    void setVisibilite(Visibilite nvVisibilite);

// sortie flux
    virtual void sortieFlux(std::ostream &os) const;

private:
    Faction _faction;

    uint16_t _pointsVie;
    uint16_t _nbMunitions;
    uint16_t _nbProvisions;

    Visibilite _visibilite;

    uint16_t const _MAX_POINTS_VIE;
    uint16_t const _MAX_NB_MUNITIONS;
    uint16_t const _MAX_NB_PROVISIONS;
};
