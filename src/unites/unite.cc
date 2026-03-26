#include "unite.hh"

Unite::Unite(unsigned int pointsVie,
             unsigned int nbMunitions) :
    _pointsVie(pointsVie),
    _nbMunitions(nbMunitions)
{}

unsigned int Unite::getPointsVie() const
{
    return _pointsVie;
}

unsigned int Unite::getNbMunitions() const
{
    return _nbMunitions;
}

bool Unite::estOperationnelle() const
{
    return _pointsVie > 0;
}

void Unite::prendreDegats(unsigned int degats)
{
    int nvPointsVie = _pointsVie - degats;
    _pointsVie = std::max(0, nvPointsVie);
}

void Unite::attaquerUnite(std::shared_ptr<Unite> unite)
{
    if (_nbMunitions > 0) {
        unsigned int pointsAttaque;
        if (unite->estLegere()) pointsAttaque = getPointsAttaqueLegere();
        else pointsAttaque = getPointsAttaqueLourde();

        unite->prendreDegats(pointsAttaque);
        _nbMunitions--;
    }
    // else erreur ??
}

void Unite::sortieFlux(std::ostream &os) const
{
    os << " pointsVie=" << _pointsVie
       << " pointsAttaqueLegere=" << getPointsAttaqueLegere()
       << " pointsAttaqueLourde=" << getPointsAttaqueLourde()
       << " capaciteDeplacement=" << getCapaciteDeplacement()
       << " distanceAttaque=" << getDistanceAttaque()
       << " nbMunitions=" << getNbMunitions()
       << std::endl;
}
