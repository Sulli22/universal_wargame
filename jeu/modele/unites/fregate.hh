#pragma once

#include <unitemarine.hh>

class Fregate : public UniteMarine {
public:
    Fregate(Faction faction,
            stat pointsVie = _POINTS_BOUCLIER_INIT,
            stat nbMunitions = _NB_MUNITIONS_INIT,
            stat nbProvisions = _NB_PROVISIONS_INIT,
            stat pointsBouclier = _POINTS_BOUCLIER_INIT);

    std::string getNom() const override;
    stat getPointsAttaqueLegere() const override;
    stat getPointsAttaqueLourde() const override;
    stat getCapaciteDeplacement() const override;
    stat getDistanceAttaque() const override;

private:
    static const stat _POINTS_VIE_INIT = 60;
    static const stat _NB_MUNITIONS_INIT = 12;
    static const stat _NB_PROVISIONS_INIT = 45;
    static const stat _POINTS_BOUCLIER_INIT = 30;
};
