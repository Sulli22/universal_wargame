#include "sommet.hh"
#include <iostream>

Sommet::Sommet()
{

}

std::shared_ptr<UniteAerienne> Sommet::getUniteHaute() const {
    return _uniteHaute;
}

void Sommet::setUniteHaute(std::shared_ptr<UniteAerienne> nvUniteHaute) {
    if (!_uniteHaute && nvUniteHaute) {
        _uniteHaute = nvUniteHaute;
    }
    else std::cerr<<"L'unité n'a pas pu être ajoutée";
}
