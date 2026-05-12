#pragma once

#include "uniteterrestrelegere.hh"

class Infanterie : public UniteTerrestreLegere {
public:
    Infanterie(Faction faction,
               stat pointsVie = _POINTS_VIE_INIT,
               stat nbMunitions = _NB_MUNITIONS_INIT,
               stat nbProvisions = _NB_PROVISIONS_INIT);

    virtual std::string getNom() const override;
    stat getPointsAttaqueLegere() const override;
    stat getPointsAttaqueLourde() const override;
    stat getCapaciteDeplacement() const override;
    stat getDistanceAttaque() const override;
    stat getTaille() const override;

protected:
    static const stat _POINTS_VIE_INIT = 30;
    static const stat _NB_MUNITIONS_INIT = 16;
    static const stat _NB_PROVISIONS_INIT = 20;
};
