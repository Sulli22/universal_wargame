#pragma once

#include "uniteterrestrelegere.hh"

class Infanterie : public UniteTerrestreLegere {
public:
    Infanterie(usint pointsVie = _POINTS_VIE_INIT,
               usint nbMunitions = _NB_MUNITIONS_INIT,
               usint nbProvisions = _NB_PROVISIONS_INIT);

    virtual std::string getNom() const override;
    usint getPointsAttaqueLegere() const override;
    usint getPointsAttaqueLourde() const override;
    usint getCapaciteDeplacement() const override;
    usint getDistanceAttaque() const override;
    usint getTaille() const override;

protected:
    static const usint _POINTS_VIE_INIT = 50;
    static const usint _NB_MUNITIONS_INIT = 16;
    static const usint _NB_PROVISIONS_INIT = 12;
};
