#pragma once

#include <unitemarine.hh>

class Fregate : public UniteMarine {
public:
    Fregate(Faction faction,
            Stat pointsVie = _POINTS_BOUCLIER_INIT,
            Stat nbMunitions = _NB_MUNITIONS_INIT,
            Stat nbProvisions = _NB_PROVISIONS_INIT,
            Stat pointsBouclier = _POINTS_BOUCLIER_INIT);

    std::string getNom() const override;
    Stat getPointsAttaqueLegere() const override;
    Stat getPointsAttaqueLourde() const override;
    Stat getCapaciteDeplacement() const override;
    Stat getDistanceAttaque() const override;

private:
    static const Stat _POINTS_VIE_INIT = 50;
    static const Stat _NB_MUNITIONS_INIT = 15;
    static const Stat _NB_PROVISIONS_INIT = 55;
    static const Stat _POINTS_BOUCLIER_INIT = 30;
};
