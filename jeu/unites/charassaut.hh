#pragma once

#include <uniteterrestrelourde.hh>

class CharAssaut : public UniteTerrestreLourde
{
public:
    CharAssaut(Faction faction,
               usint pointsVie = _POINTS_VIE_INIT,
               usint nbMunitions = _NB_MUNITIONS_INIT,
               usint nbProvisions = _NB_PROVISIONS_INIT,
               usint pointsBouclier = _POINTS_BOUCLIER_INIT);

    std::string getNom() const override;
    usint getPointsAttaqueLegere() const override;
    usint getPointsAttaqueLourde() const override;
    usint getCapaciteDeplacement() const override;
    usint getDistanceAttaque() const override;

private:
    static const usint _POINTS_VIE_INIT = 40;
    static const usint _NB_MUNITIONS_INIT = 8;
    static const usint _NB_PROVISIONS_INIT = ;
    static const usint _POINTS_BOUCLIER_INIT = 20;
};
