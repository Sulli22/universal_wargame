#pragma once

#include <uniteterrestrelegere.hh>

class Artillerie : public UniteTerrestreLegere {
public:
    Artillerie(Faction faction,
               Stat pointsVie = _POINTS_VIE_INIT,
               Stat nbMunitions = _NB_MUNITIONS_INIT,
               Stat nbProvisions = _NB_PROVISIONS_INIT);

    std::string getNom() const override;
    Stat getPointsAttaqueLegere() const override;
    Stat getPointsAttaqueLourde() const override;
    Stat getCapaciteDeplacement() const override;
    Stat getDistanceAttaque() const override;
    Stat getTaille() const override;

private:
    static const Stat _POINTS_VIE_INIT = 35;
    static const Stat _NB_MUNITIONS_INIT = 8;
    static const Stat _NB_PROVISIONS_INIT = 30;
};
