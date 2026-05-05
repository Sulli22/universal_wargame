#pragma once

#include <uniteterrestrelegere.hh>

class Artillerie : public UniteTerrestreLegere {
public:
    Artillerie(Faction faction,
               uint16_t pointsVie = _POINTS_VIE_INIT,
               uint16_t nbMunitions = _NB_MUNITIONS_INIT,
               uint16_t nbProvisions = _NB_PROVISIONS_INIT);

    virtual std::string getNom() const override;
    uint16_t getPointsAttaqueLegere() const override;
    uint16_t getPointsAttaqueLourde() const override;
    uint16_t getCapaciteDeplacement() const override;
    uint16_t getDistanceAttaque() const override;
    uint16_t getTaille() const override;

private:
    static const uint16_t _POINTS_VIE_INIT = 35;
    static const uint16_t _NB_MUNITIONS_INIT = 12;
    static const uint16_t _NB_PROVISIONS_INIT = 30;
};
