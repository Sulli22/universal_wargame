#pragma once

#include <unitemarine.hh>

class Fregate : public UniteMarine {
public:
    Fregate(Faction faction,
            uint16_t pointsVie = _POINTS_BOUCLIER_INIT,
            uint16_t nbMunitions = _NB_MUNITIONS_INIT,
            uint16_t nbProvisions = _NB_PROVISIONS_INIT,
            uint16_t pointsBouclier = _POINTS_BOUCLIER_INIT);

    std::string getNom() const override;
    uint16_t getPointsAttaqueLegere() const override;
    uint16_t getPointsAttaqueLourde() const override;
    uint16_t getCapaciteDeplacement() const override;
    uint16_t getDistanceAttaque() const override;

private:
    static const uint16_t _POINTS_VIE_INIT = 60;
    static const uint16_t _NB_MUNITIONS_INIT = 12;
    static const uint16_t _NB_PROVISIONS_INIT = 45;
    static const uint16_t _POINTS_BOUCLIER_INIT = 30;
};
