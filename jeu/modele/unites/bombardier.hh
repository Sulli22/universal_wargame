#pragma once

#include <uniteaerienne.hh>

class Bombardier : public UniteAerienne {
public:
    Bombardier(Faction faction,
               Stat pointsVie = _POINTS_VIE_INIT,
               Stat nbMunitions = _NB_MUNITIONS_INIT,
               Stat nbProvisions = _NB_PROVISIONS_INIT,
               Stat pointsBouclier = _POINTS_BOUCLIER_INIT);

    std::string getNom() const override;
    Stat getPointsAttaqueLegere() const override;
    Stat getPointsAttaqueLourde() const override;
    Stat getCapaciteDeplacement() const override;
    Stat getDistanceAttaque() const override;

private:
    static const Stat _POINTS_VIE_INIT = 40;
    static const Stat _NB_MUNITIONS_INIT = 7;
    static const Stat _NB_PROVISIONS_INIT = 30;
    static const Stat _POINTS_BOUCLIER_INIT = 30;
};

