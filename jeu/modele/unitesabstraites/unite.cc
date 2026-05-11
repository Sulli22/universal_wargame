#include "unite.hh"

Unite::Unite(Faction faction, stat pointsVie, stat nbMunitions,
             stat nbProvisions, Visibilite visibilite):
    _faction(faction),
    _pointsVie(pointsVie), _nbMunitions(nbMunitions),
    _nbProvisions(nbProvisions), _visibilite(visibilite),
    _MAX_POINTS_VIE(pointsVie), _MAX_NB_MUNITIONS(nbMunitions),
    _MAX_NB_PROVISIONS(nbProvisions)
{}

Faction Unite::getFaction() const
{
    return _faction;
}

stat Unite::getPointsVie() const
{
    return _pointsVie;
}

stat Unite::getNbMunitions() const
{
    return _nbMunitions;
}

stat Unite::getNbProvisions() const
{
    return _nbProvisions;
}

Unite::Visibilite Unite::getVisibilite() const
{
    return _visibilite;
}

stat Unite::getMaxPointsVie() const
{
    return _MAX_POINTS_VIE;
}

stat Unite::getMaxNbMunitions() const
{
    return _MAX_NB_MUNITIONS;
}

stat Unite::getMaxNbProvisions() const
{
    return _MAX_NB_PROVISIONS;
}

void Unite::regagnerViePartielle()
{
    stat nvPointsVie = _pointsVie + (_MAX_POINTS_VIE / 5); // plus un cinquieme
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

std::set<indiceAction> Unite::getIndicesActionsPossibles() const
{
    std::set<indiceAction> indices;

    if (_nbProvisions > 0)
        indices.insert(0);  // deplacement

    if (_nbMunitions > 0)
        indices.insert(1);  // attaque

    return indices;
}

bool Unite::estOperationnelle() const
{
    return _pointsVie > 0;
}

std::string Unite::getChaineVisibilite() const
{
    switch (_visibilite) {
    case Visibilite::nulle:     return "nulle";
    case Visibilite::partielle: return "partielle";
    case Visibilite::totale:    return "totale";

    default:
        throw std::runtime_error("Erreur : Visibilite inconnue");
    }
}

void Unite::sortieFlux(std::ostream &os) const
{
    os << getNom()
    << " faction=" << (_faction == Faction::bleue ? "bleue" : "rouge")
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

void Unite::prendreDegats(stat degats)
{
    int nvPointsVie = _pointsVie - degats;
    _pointsVie = std::max(0, nvPointsVie);
}

void Unite::attaquerUnite(Unite *unite)
{
    if (_nbMunitions > 0 && unite) {
        stat pointsAttaque;
        if (unite->estLegere())
            pointsAttaque = getPointsAttaqueLegere();
        else
            pointsAttaque = getPointsAttaqueLourde();

        unite->prendreDegats(pointsAttaque);
        _nbMunitions--;
    }
}

void Unite::utiliserProvisions(stat nbProvisions)
{
    int nvNbProvisions = _nbProvisions - nbProvisions;
    _nbProvisions = std::max(0, nvNbProvisions);
}

void Unite::setVisibilite(Visibilite nvVisibilite)
{
    _visibilite = nvVisibilite;
}
