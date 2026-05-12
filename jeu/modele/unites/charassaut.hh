#pragma once

#include <uniteterrestrelourde.hh>

class CharAssaut : public UniteTerrestreLourde
{
public:
    CharAssaut(Faction faction,
               stat pointsVie = _POINTS_VIE_INIT,
               stat nbMunitions = _NB_MUNITIONS_INIT,
               stat nbProvisions = _NB_PROVISIONS_INIT,
               stat pointsBouclier = _POINTS_BOUCLIER_INIT);

    std::string getNom() const override;
    stat getPointsAttaqueLegere() const override;
    stat getPointsAttaqueLourde() const override;
    stat getCapaciteDeplacement() const override;
    stat getDistanceAttaque() const override;

private:
    static const stat _POINTS_VIE_INIT = 40;
    static const stat _NB_MUNITIONS_INIT = 6;
    static const stat _NB_PROVISIONS_INIT = 20;
    static const stat _POINTS_BOUCLIER_INIT = 20;
};
