#include "sommet.hh"
#include <iostream>

unsigned int Sommet::_nextId(0);

Sommet::Sommet():_id(_nextId++)
{}

std::shared_ptr<UniteAerienne> Sommet::getUniteHaute() const
{
    return _uniteHaute;
}

unsigned int Sommet::getId() const {
    return _id;
}

void Sommet::setUniteHaute(std::shared_ptr<UniteAerienne> nvUniteHaute)
{
    if (!_uniteHaute && nvUniteHaute)
        _uniteHaute = nvUniteHaute;
    else
        std::cerr << "L'unité n'a pas pu être ajoutée" << std::endl;
}
