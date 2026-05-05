#pragma once

#include <uniteaerienne.hh>

class Chasseur : public UniteAerienne {
public:
    Chasseur(Faction faction,
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
    static const uint16_t _POINTS_VIE_INIT = 35;
    static const uint16_t _NB_MUNITIONS_INIT = 20;
    static const uint16_t _NB_PROVISIONS_INIT = 80;
    static const uint16_t _POINTS_BOUCLIER_INIT = 5;
};
