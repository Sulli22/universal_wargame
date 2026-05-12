#pragma once

#include <uniteterrestrelegere.hh>

class Artillerie : public UniteTerrestreLegere {
public:
    Artillerie(Faction faction,
               stat pointsVie = _POINTS_VIE_INIT,
               stat nbMunitions = _NB_MUNITIONS_INIT,
               stat nbProvisions = _NB_PROVISIONS_INIT);

    virtual std::string getNom() const override;
    stat getPointsAttaqueLegere() const override;
    stat getPointsAttaqueLourde() const override;
    stat getCapaciteDeplacement() const override;
    stat getDistanceAttaque() const override;
    stat getTaille() const override;

private:
    static const stat _POINTS_VIE_INIT = 35;
    static const stat _NB_MUNITIONS_INIT = 8;
    static const stat _NB_PROVISIONS_INIT = 30;
};
