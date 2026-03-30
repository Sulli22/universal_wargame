#include "unite.hh"

Unite::Unite(usint pointsVie, usint nbMunitions, usint nbProvisions,
             Visibilite visibilite):
    _pointsVie(pointsVie), _nbMunitions(nbMunitions),
    _nbProvisions(nbProvisions), _visibilite(visibilite),
    _MAX_POINTS_VIE(pointsVie), _MAX_NB_MUNITIONS(nbMunitions),
    _MAX_NB_PROVISIONS(nbProvisions)
{}

usint Unite::getPointsVie() const
{
    return _pointsVie;
}

usint Unite::getNbMunitions() const
{
    return _nbMunitions;
}

usint Unite::getNbProvisions() const
{
    return _nbProvisions;
}

Unite::Visibilite Unite::getVisibilite() const
{
    return _visibilite;
}

usint Unite::getMaxPointsVie() const
{
    return _MAX_POINTS_VIE;
}

usint Unite::getMaxNbMunitions() const
{
    return _MAX_NB_MUNITIONS;
}

usint Unite::getMaxNbProvisions() const
{
    return _MAX_NB_PROVISIONS;
}

void Unite::regagnerViePartielle()
{
    usint nvPointsVie = _pointsVie + (_MAX_POINTS_VIE / 5); // plus un cinquieme
    _pointsVie = std::min(nvPointsVie, _MAX_POINTS_VIE);
}

void Unite::rechargerMunitions()
{
    _nbMunitions = _MAX_NB_MUNITIONS;
}

void Unite::rechargerProvisions()
{
    _nbProvisions = _MAX_NB_PROVISIONS;
}

bool Unite::estOperationnelle() const
{
    return _pointsVie > 0;
}

std::string Unite::getChaineVisibilite() const
{
    switch (_visibilite) {
        case Visibilite::nulle: return "nulle";
        case Visibilite::partielle: return "partielle";
        case Visibilite::totale: return "totale";
    }
    return "";
}

void Unite::sortieFlux(std::ostream &os) const
{
    os << getNom()
    << " pointsVie=" << _pointsVie << "/" << _MAX_POINTS_VIE
    << " nbMunitions=" << getNbMunitions() << "/" << _MAX_NB_MUNITIONS
    << " nbProvisions=" << getNbProvisions() << "/" << _MAX_NB_PROVISIONS
    << " pointsAttaqueLegere=" << getPointsAttaqueLegere()
    << " pointsAttaqueLourde=" << getPointsAttaqueLourde()
    << " capaciteDeplacement=" << getCapaciteDeplacement()
    << " distanceAttaque=" << getDistanceAttaque()
    << " estLegere=" << estLegere()
    << " estOperationnelle=" << estOperationnelle()
    << " visibilite=" << getChaineVisibilite();
}

void Unite::prendreDegats(usint degats)
{
    int nvPointsVie = _pointsVie - degats;
    _pointsVie = std::max(0, nvPointsVie);
}

void Unite::attaquerUnite(std::shared_ptr<Unite> unite)
{
    if (_nbMunitions > 0 && unite) {
        usint pointsAttaque;
        if (unite->estLegere())
            pointsAttaque = getPointsAttaqueLegere();
        else
            pointsAttaque = getPointsAttaqueLourde();

        unite->prendreDegats(pointsAttaque);
        _nbMunitions--;
    }
}

void Unite::utiliserProvisions(usint nbProvisions)
{
    int nvNbProvisions = _nbProvisions - nbProvisions;
    _nbProvisions = std::max(0, nvNbProvisions);
}

void Unite::setVisibilite(Visibilite nvVisibilite)
{
    _visibilite = nvVisibilite;
}
