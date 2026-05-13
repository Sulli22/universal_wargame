#pragma once

#include "uniteterrestrelegere.hh"

class Infanterie : public UniteTerrestreLegere {
public:
    Infanterie(Faction faction,
               Stat pointsVie = _POINTS_VIE_INIT,
               Stat nbMunitions = _NB_MUNITIONS_INIT,
               Stat nbProvisions = _NB_PROVISIONS_INIT);

    virtual std::string getNom() const override;
    Stat getPointsAttaqueLegere() const override;
    Stat getPointsAttaqueLourde() const override;
    Stat getCapaciteDeplacement() const override;
    Stat getDistanceAttaque() const override;
    Stat getTaille() const override;

protected:
    static const Stat _POINTS_VIE_INIT = 30;
    static const Stat _NB_MUNITIONS_INIT = 16;
    static const Stat _NB_PROVISIONS_INIT = 20;
};
