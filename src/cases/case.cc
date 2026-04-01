#include "case.hh"
#include <iostream>

Case::Case(const Position &pos) :
    _pos(pos)
{}

const Position &Case::getPos() const
{
    return _pos;
}


std::shared_ptr<UniteAerienne> Case::getUniteAerienne() const
{
    return _uniteAerienne;
}

void Case::setUniteAerienne(std::shared_ptr<UniteAerienne> nvUniteAerienne)
{
    if (!_uniteAerienne && nvUniteAerienne)
        _uniteAerienne = nvUniteAerienne;
    else
        std::cerr << "L'unité n'a pas pu être ajoutée" << std::endl;
}
