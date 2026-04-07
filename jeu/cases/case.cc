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
    if (!_uniteAerienne && nvUniteAerienne)
        _uniteAerienne = std::move(nvUniteAerienne);
    else
        std::cerr << "L'unité n'a pas pu être ajoutée" << std::endl;
}

void Case::deplacerUniteAerienne(Case & arrivee)
{
    if (!arrivee.getUniteAerienne())
        arrivee.setUniteAerienne(std::move(_uniteAerienne));
    else
        throw std::runtime_error("Erreur : Il y a déjà une unité aérienne");
}

void Case::sortieFlux(std::ostream &os) const
{
    //_pos.sortieFlux(os);
}
