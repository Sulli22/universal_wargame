#include "unite.hh"

Unite::Unite(usint pointsVie, usint nbMunitions) :
    _pointsVie(pointsVie), _nbMunitions(nbMunitions),
    _MAX_POINTS_VIE(pointsVie), _MAX_NB_MUNITIONS(nbMunitions)
{}

usint Unite::getPointsVie() const
{
    return _pointsVie;
}

usint Unite::getNbMunitions() const
{
    return _nbMunitions;
}

usint Unite::getMaxPointsVie() const
{
    return _MAX_POINTS_VIE;
}

usint Unite::getMaxNbMunitions() const
{
    return _MAX_NB_MUNITIONS;
}

void Unite::regagnerViePartielle()
{
    usint viePartielle = _MAX_POINTS_VIE / 5; // un cinquieme
    _pointsVie += viePartielle;
}

void Unite::rechargerMunitions()
{
    _nbMunitions = _MAX_NB_MUNITIONS;
}

bool Unite::estOperationnelle() const
{
    return _pointsVie > 0;
}

void Unite::prendreDegats(usint degats)
{
    int nvPointsVie = _pointsVie - degats;
    _pointsVie = std::max(0, nvPointsVie);
}

void Unite::attaquerUnite(std::shared_ptr<Unite> unite)
{
    if (_nbMunitions > 0) {
        usint pointsAttaque;
        if (unite->estLegere())
            pointsAttaque = getPointsAttaqueLegere();
        else
            pointsAttaque = getPointsAttaqueLourde();

        unite->prendreDegats(pointsAttaque);
        _nbMunitions--;
    }
    // else erreur pas assez de muntions TODO
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
