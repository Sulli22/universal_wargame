#pragma once

#include "unitemarine.hh"

class SousMarin : public UniteMarine {
public:
    SousMarin(Faction faction,
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
    static const stat _POINTS_VIE_INIT = 90;
    static const stat _NB_MUNITIONS_INIT = 15;
    static const stat _NB_PROVISIONS_INIT = 140;
    static const stat _POINTS_BOUCLIER_INIT = 30;
};
