#pragma once

#include <ostream>
#include <memory>

using usint = unsigned short int;

class Unite {
public:
    Unite(usint pointsVie, usint nbMunitions, usint nbProvisions);

    usint getPointsVie() const;
    usint getNbMunitions() const;
    usint getNbProvisions() const;

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
    virtual void prendreDegats(usint degats);
    void attaquerUnite(std::shared_ptr<Unite> unite);
    void utiliserProvisions(usint nbProvisions);
    virtual void sortieFlux(std::ostream &os) const;

private:
    usint _pointsVie;
    usint _nbMunitions;
    usint _nbProvisions;

    usint const _MAX_POINTS_VIE;
    usint const _MAX_NB_MUNITIONS;
    usint const _MAX_NB_PROVISIONS;
};
