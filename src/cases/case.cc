#include "case.hh"
#include <iostream>

Case::Case(const Position &pos):
    _pos(pos)
{}

const Position &Case::getPos() const
{
    return _pos;
}


std::shared_ptr<UniteAerienne> Case::getUniteHaute() const
{
    return _uniteHaute;
}

void Case::setUniteHaute(std::shared_ptr<UniteAerienne> nvUniteHaute)
{
    if (!_uniteHaute && nvUniteHaute)
        _uniteHaute = nvUniteHaute;
    else
        std::cerr << "L'unité n'a pas pu être ajoutée" << std::endl;
}
