#pragma once

#include "uniteterrestrelegere.hh"

class Infanterie : public UniteTerrestreLegere {
public:
    Infanterie(Faction faction,
               uint16_t pointsVie = _POINTS_VIE_INIT,
               uint16_t nbMunitions = _NB_MUNITIONS_INIT,
               uint16_t nbProvisions = _NB_PROVISIONS_INIT);

    virtual std::string getNom() const override;
    uint16_t getPointsAttaqueLegere() const override;
    uint16_t getPointsAttaqueLourde() const override;
    uint16_t getCapaciteDeplacement() const override;
    uint16_t getDistanceAttaque() const override;
    uint16_t getTaille() const override;

protected:
    static const uint16_t _POINTS_VIE_INIT = 30;
    static const uint16_t _NB_MUNITIONS_INIT = 16;
    static const uint16_t _NB_PROVISIONS_INIT = 30;
};
