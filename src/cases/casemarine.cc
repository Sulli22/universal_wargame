#include "casemarine.hh"
#include <iostream>
CaseMarine::CaseMarine(const Position &pos):Case(pos)
{

}


std::shared_ptr<UniteMarine> CaseMarine::getUniteBasse() const
{
    return _uniteBasse;
}

void CaseMarine::setUniteBasse(std::shared_ptr<UniteMarine> nvUniteBasse) {
    if (!_uniteBasse && nvUniteBasse)
        _uniteBasse = nvUniteBasse;
    else
        std::cerr << "L'unité ne peut pas être ajoutée" << std::endl;
}

