#include "case.hh"
#include <iostream>

Case::Case(const Position &pos) :
    _pos(pos)
{}

const Position &Case::getPos() const
{
    return _pos;
}

const UniteAerienne *Case::getUniteAerienne() const
{
    return _uniteAerienne.get();
}

void Case::setUniteAerienne(std::unique_ptr<UniteAerienne> nvUniteAerienne)
{
    if (_uniteAerienne)
        throw std::runtime_error("Erreur : La place est deja occupee.");
    if (!nvUniteAerienne)
        throw std::invalid_argument("Erreur : Une unite nulle ne peut pas etre ajoutee.");
    _uniteAerienne = std::move(nvUniteAerienne);
}

void Case::deplacerUniteAerienne(Case & arrivee)
{
    if (!arrivee.getUniteAerienne())
        arrivee.setUniteAerienne(std::move(_uniteAerienne));
    else
        throw std::runtime_error("Erreur : La place est deja occupee.");
}

Faction Case::getFaction() const
{
    return _uniteAerienne ? _uniteAerienne->getFaction() : Faction::neutre;
}

void Case::sortieFlux(std::ostream &os) const
{
    _pos.sortieFlux(os);
}

void Case::afficherDetails(std::ostream &os) const
{
    os << "-> Case : "; sortieFlux(os);
    if (_uniteAerienne) {
        os << std::endl << "Unite aerienne = [";
        _uniteAerienne->sortieFlux(os);
        os << "]";
    }
}
