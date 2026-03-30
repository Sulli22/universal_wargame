#include "infanterie.hh"

Infanterie::Infanterie() :
    Unite(_POINTS_VIE_INIT, _NB_MUNITIONS_INIT, _NB_PROVISIONS_INIT),
    UniteTerrestreLegere(_POINTS_VIE_INIT, _NB_MUNITIONS_INIT,
                           _NB_PROVISIONS_INIT)
{}

std::string Infanterie::getNom() const
{
    return "Infanterie";
}

usint Infanterie::getPointsAttaqueLegere() const
{
    return 10;
}

usint Infanterie::getPointsAttaqueLourde() const
{
    return 15;
}

usint Infanterie::getCapaciteDeplacement() const
{
    return 2;
}

usint Infanterie::getDistanceAttaque() const
{
    return 1;
}

usint Infanterie::getTaille() const
{
    return 1;
}
