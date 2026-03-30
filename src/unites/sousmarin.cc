#include "sousmarin.hh"

SousMarin::SousMarin() :
    Unite(_POINTS_VIE_INIT, _NB_MUNITIONS_INIT, _NB_PROVISIONS_INIT,
            Visibilite::nulle),
    UniteMarine(_POINTS_VIE_INIT, _NB_MUNITIONS_INIT, _NB_PROVISIONS_INIT,
                  _POINTS_BOUCLIER_INIT)
{}

std::string SousMarin::getNom() const
{
    return "Sous-Marin";
}

usint SousMarin::getPointsAttaqueLegere() const
{
    return 25;
}

usint SousMarin::getPointsAttaqueLourde() const
{
    return 40;
}

usint SousMarin::getCapaciteDeplacement() const
{
    return 10;
}

usint SousMarin::getDistanceAttaque() const
{
    return 20;
}
