#pragma once

#include <uniteaerienne.hh>

class Chasseur : public UniteAerienne {
public:
    Chasseur(Faction faction,
             usint pointsVie = _POINTS_VIE_INIT,
             usint nbMunitions = _NB_MUNITIONS_INIT,
             usint nbProvisions = _NB_PROVISIONS_INIT,
             usint pointsBouclier = _POINTS_BOUCLIER_INIT);

    std::string getNom() const override;
    usint getPointsAttaqueLegere() const override;
    usint getPointsAttaqueLourde() const override;
    usint getCapaciteDeplacement() const override;
    usint getDistanceAttaque() const override;
private:
    static const usint _POINTS_VIE_INIT = 35;
    static const usint _NB_MUNITIONS_INIT = 20;
    static const usint _NB_PROVISIONS_INIT = 22;
    static const usint _POINTS_BOUCLIER_INIT = 5;
};
