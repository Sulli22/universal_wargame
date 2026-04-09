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
    if (_uniteBasse)
        throw std::runtime_error("Erreur : La place est deja occupee.");
    if (!nvUniteBasse)
        throw std::invalid_argument("Erreur : Une unite nulle ne peut pas etre ajoutee.");
    if (getFaction() != Faction::neutre &&
        nvUniteBasse->getFaction() != getFaction())
        throw std::invalid_argument("Erreur : Une unite d'une autre faction ne peut pas etre ajoutee.");
    _uniteBasse = std::move(nvUniteBasse);
}

void CaseMarine::deplacerUniteBasse(CaseMarine &arrive)
{
    if (!arrive.getUniteBasse())
        arrive.setUniteBasse(std::move(_uniteBasse));
    else
        throw std::runtime_error("Erreur : La place est deja occupee.");
}

usint CaseMarine::coutDeplacement(Unite *unite) const
{
    auto uniteMarine = dynamic_cast<UniteMarine *>(unite);
    auto uniteAerienne = dynamic_cast<UniteAerienne *>(unite);

    // seules les unites marines et aeriennes peuvent passer
    if (uniteMarine || uniteAerienne)
        return 1;
    return std::numeric_limits<usint>::infinity();
}

Faction CaseMarine::getFaction() const
{
    auto faction = Case::getFaction();
    if (faction != Faction::neutre) return faction;
    if (_uniteBasse) return _uniteBasse->getFaction();
    return Faction::neutre;
}

void CaseMarine::afficherDetails(std::ostream &os) const
{
    Case::afficherDetails(os); os << std::endl;
    os << "Type = Eau" << std::endl;
    if (_uniteBasse) {
        os << "Unite Basse = [";
        _uniteBasse->sortieFlux(os);
        os << "]" << std::endl;
    }
}
