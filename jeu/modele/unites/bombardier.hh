#pragma once

#include <uniteaerienne.hh>

class Bombardier : public UniteAerienne {
public:
    Bombardier(Faction faction,
               uint16_t pointsVie = _POINTS_VIE_INIT,
               uint16_t nbMunitions = _NB_MUNITIONS_INIT,
               uint16_t nbProvisions = _NB_PROVISIONS_INIT,
               uint16_t pointsBouclier = _POINTS_BOUCLIER_INIT);

    std::string getNom() const override;
    uint16_t getPointsAttaqueLegere() const override;
    uint16_t getPointsAttaqueLourde() const override;
    uint16_t getCapaciteDeplacement() const override;
    uint16_t getDistanceAttaque() const override;

private:
    static const uint16_t _POINTS_VIE_INIT = 50;
    static const uint16_t _NB_MUNITIONS_INIT = 16;
    static const uint16_t _NB_PROVISIONS_INIT = 40;
    static const uint16_t _POINTS_BOUCLIER_INIT = 30;
};

