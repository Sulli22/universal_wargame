#include "sommetmarin.hh"
#include <iostream>

SommetMarin::SommetMarin()
{}

std::shared_ptr<UniteMarine> SommetMarin::getUniteBasse() const
{
    return _uniteBasse;
}

void SommetMarin::setUniteBasse(std::shared_ptr<UniteMarine> nvUniteBasse) {
    if (!_uniteBasse && nvUniteBasse)
        _uniteBasse = nvUniteBasse;
    else
        std::cerr << "L'unité ne peut pas être ajoutée" << std::endl;
}
