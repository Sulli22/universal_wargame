#include "casemarine.hh"
#include <limits>

CaseMarine::CaseMarine(const Position &pos):
    Case(pos)
{}

const UniteMarine *CaseMarine::getUniteBasse() const
{
    return _uniteBasse.get();
}

void CaseMarine::setUniteBasse(std::unique_ptr<UniteMarine> nvUniteBasse)
{
    if (!_uniteBasse && nvUniteBasse)
        _uniteBasse = std::move(nvUniteBasse);
    else
        throw "L'unité ne peut pas être ajoutée";
}

void CaseMarine::deplacerUniteBasse(CaseMarine &arrive)
{
    if (!arrive.getUniteBasse())
        arrive.setUniteBasse(std::move(_uniteBasse));
    else
        throw "Il y a déjà une untité basse sur cette case";
}

usint CaseMarine::coutDeplacement(Unite *unite) const
{
    auto pUniteMarine = dynamic_cast<UniteMarine *>(unite);
    auto pUniteAerienne = dynamic_cast<UniteAerienne *>(unite);

    // seules les unités marines et aeriennes peuvent passer
    if (pUniteMarine || pUniteAerienne)
        return 1;
    return std::numeric_limits<usint>::infinity();
}

void CaseMarine::sortieFlux(std::ostream &os) const
{
    Case::sortieFlux(os);
    os << "E";
}
