#pragma once

#include <ostream>
#include <memory>

using usint = unsigned short int;

class Unite {
public:
    Unite(usint pointsVie, usint nbMunitions);

    usint getPointsVie() const;
    usint getNbMunitions() const;

    virtual usint getMaxPointsVie() const;
    virtual usint getMaxNbMunitions() const;
    void regagnerViePartielle();
    void rechargerMunitions();

    virtual usint getPointsAttaqueLegere() const =0;
    virtual usint getPointsAttaqueLourde() const =0;
    virtual usint getCapaciteDeplacement() const =0;
    virtual usint getDistanceAttaque() const =0;

    virtual bool estLegere() const =0;
    bool estOperationnelle() const;
    virtual void prendreDegats(usint degats);
    void attaquerUnite(std::shared_ptr<Unite> unite);

    virtual void sortieFlux(std::ostream &os) const;

private:
    usint _pointsVie;
    usint _nbMunitions;
    usint _MAX_POINTS_VIE;
    usint _MAX_NB_MUNITIONS;
};
