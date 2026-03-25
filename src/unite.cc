#include "Unite.hh"

/*
 *      Constructeur
 */
Unite::Unite(int pointsVie, int pointsAttaque, int capaciteDeDeplacement) :
    _pointsVie(pointsVie),
    _pointsAttaque(pointsAttaque),
    _capaciteDeDeplacement(capaciteDeDeplacement)
{}

/*
 *      Getters et Setters
 */
int Unite::getPointsVie() const
{
    return _pointsVie;
}

int Unite::getPointsAttaque() const
{
    return _pointsAttaque;
}

int Unite::getCapaciteDeDeplacement() const
{
    return _capaciteDeDeplacement;
}

void Unite::setPointsVie(int nvPointsVie)
{
    _pointsVie = nvPointsVie;
}

void Unite::setPointsAttaque(int nvPointsAttaque)
{
    _pointsAttaque = nvPointsAttaque;
}

void Unite::setCapaciteDeDeplacement(int nvCapaciteDeDeplacement)
{
    _capaciteDeDeplacement = nvCapaciteDeDeplacement;
}


void Unite::attaquerUnite(Unite &unite)
{
    unite.setPointsVie(unite.getPointsVie() - _pointsAttaque);
}
