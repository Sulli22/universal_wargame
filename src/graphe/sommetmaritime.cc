#include "sommetmaritime.hh"
#include <iostream>

SommetMaritime::SommetMaritime()
{}

std::shared_ptr<UniteMaritime> SommetMaritime::getUniteBasse() const
{
    return _uniteBasse;
}

void SommetMaritime::setUniteBasse(std::shared_ptr<UniteMaritime> nvUniteBasse) {
    if (!_uniteBasse && nvUniteBasse)
        _uniteBasse = nvUniteBasse;
    else
        std::cerr << "L'unité ne peut pas être ajoutée" << std::endl;
}
