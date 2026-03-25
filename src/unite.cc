#include "unite.hh"

/*
 *      Constructeur
 */
Unite::Unite(int pointsVie, int pointsAttaque, int capaciteDeDeplacement, unsigned int distanceAttaque) :
    _pointsVie(pointsVie),
    _pointsAttaque(pointsAttaque),
    _capaciteDeDeplacement(capaciteDeDeplacement),
    _distanceAttaque(distanceAttaque)
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

unsigned int Unite::getDistanceAttaque() const {
    return _distanceAttaque;
}

unsigned int Unite::getNbMunitions() const {
    return _nbMUnitions;
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

void Unite::setDistanceAttaque(unsigned int nvDistanceAttaque) {
    _distanceAttaque = nvDistanceAttaque;
}

void Unite::setNbMunitions(unsigned int nvNbMunitions) {
    _nbMUnitions = nvNbMunitions;
}

void Unite::attaquerUnite(Unite &unite)
{
    unite.setPointsVie(unite.getPointsVie() - _pointsAttaque);
}

void Unite::sortieFlux(std::ostream &os) const
{
    os << " pointsVie=" << _pointsVie
       << " pointsAttaque=" << _pointsAttaque
       << " capaciteDeDeplacement=" << _capaciteDeDeplacement
       << std::endl;
}
