#include "unite.hh"

Unite::Unite(Faction faction, Stat pointsVie, Stat nbMunitions,
             Stat nbProvisions, Visibilite visibilite):
    _faction(faction), _pointsVie(pointsVie), _nbMunitions(nbMunitions),
    _nbProvisions(nbProvisions), _visibilite(visibilite),
    _MAX_POINTS_VIE(pointsVie), _MAX_NB_MUNITIONS(nbMunitions),
    _MAX_NB_PROVISIONS(nbProvisions)
{}

Faction Unite::getFaction() const
{
    return _faction;
}

Stat Unite::getPointsVie() const
{
    return _pointsVie;
}

Stat Unite::getNbMunitions() const
{
    return _nbMunitions;
}

Stat Unite::getNbProvisions() const
{
    return _nbProvisions;
}

Unite::Visibilite Unite::getVisibilite() const
{
    return _visibilite;
}

Stat Unite::getMaxPointsVie() const
{
    return _MAX_POINTS_VIE;
}

Stat Unite::getMaxNbMunitions() const
{
    return _MAX_NB_MUNITIONS;
}

Stat Unite::getMaxNbProvisions() const
{
    return _MAX_NB_PROVISIONS;
}

void Unite::setVisibilite(Visibilite nvVisibilite)
{
    _visibilite = nvVisibilite;
}

void Unite::regagnerVie()
{
    Stat nvPointsVie = _pointsVie + (_MAX_POINTS_VIE * _MULT_RECHARGE);
    _pointsVie = std::min(nvPointsVie, _MAX_POINTS_VIE);        // sécurité contre overflow silencieux
}

void Unite::rechargerMunitions()
{
    Stat nvNbMunitions = _nbMunitions + (_MAX_NB_MUNITIONS * _MULT_RECHARGE);
    _nbMunitions = std::min(nvNbMunitions, _MAX_NB_MUNITIONS);  // sécurité contre overflow silencieux
}

void Unite::rechargerProvisions()
{
    Stat nvNbProvisions = _nbProvisions + (_MAX_NB_PROVISIONS * _MULT_RECHARGE);
    _nbProvisions = std::min(nvNbProvisions, _MAX_NB_PROVISIONS);   // sécurité contre overflow silencieux
}

std::vector<IndiceAction> Unite::getIndicesActionsPossibles() const
{
    std::vector<IndiceAction> indices;

    if (_nbProvisions > 0)
        indices.push_back(0);  // deplacement

    if (_nbMunitions > 0)
        indices.push_back(1);  // attaque

    return indices;
}

bool Unite::estOperationnelle() const
{
    return _pointsVie > 0;
}

void Unite::prendreDegats(Stat degats)
{
    int nvPointsVie = _pointsVie - degats;
    _pointsVie = std::max(0, nvPointsVie);  // sécurité contre overflow silencieux
}

void Unite::attaquerUnite(Unite *unite)
{
    if (_nbMunitions > 0 && unite) {
        Stat pointsAttaque;
        // contre des unites lourdes les points d'attaques sont différents
        // (pas même arme utilisée par exemple)
        if (unite->estLegere())
            pointsAttaque = getPointsAttaqueLegere();
        else
            pointsAttaque = getPointsAttaqueLourde();

        unite->prendreDegats(pointsAttaque);
        _nbMunitions--;     // attaquer coute des munitions
    }
}

void Unite::utiliserProvisions(Stat nbProvisions)
{
    int nvNbProvisions = _nbProvisions - nbProvisions;
    _nbProvisions = std::max(0, nvNbProvisions);
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
