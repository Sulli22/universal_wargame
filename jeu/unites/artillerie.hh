#pragma once

#include <uniteterrestrelegere.hh>

class Artillerie : public UniteTerrestreLegere {
public:
    Artillerie(Faction faction,
               usint pointsVie = _POINTS_VIE_INIT,
               usint nbMunitions = _NB_MUNITIONS_INIT,
               usint nbProvisions = _NB_PROVISIONS_INIT);

    virtual std::string getNom() const override;
    usint getPointsAttaqueLegere() const override;
    usint getPointsAttaqueLourde() const override;
    usint getCapaciteDeplacement() const override;
    usint getDistanceAttaque() const override;
    usint getTaille() const override;

protected:
    static const usint _POINTS_VIE_INIT = 35;
    static const usint _NB_MUNITIONS_INIT = 12;
    static const usint _NB_PROVISIONS_INIT = 30;
};
