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

void Unite::setPointsVie(int newPointsVie)
{
    _pointsVie = newPointsVie;
}

void Unite::setPointsAttaque(int newPointsAttaque)
{
    _pointsAttaque = newPointsAttaque;
}

void Unite::setCapaciteDeDeplacement(int newCapaciteDeDeplacement)
{
    _capaciteDeDeplacement = newCapaciteDeDeplacement;
}

void Unite::attaquerUnite(Unite &unite)
{
    unite.setPointsVie(unite.getPointsVie() - _pointsAttaque);
}
