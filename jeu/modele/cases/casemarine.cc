#include "casemarine.hh"
#include <limits>
#include <iostream>

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

    if (getFaction() != Faction::neutre && nvUniteBasse->getFaction() != getFaction())
        throw std::invalid_argument("Erreur : Une unite d'une autre faction ne peut pas etre ajoutee.");

    _uniteBasse = std::move(nvUniteBasse);
}

bool CaseMarine::peutAccueillir(Unite *unite) const
{
    auto ua = dynamic_cast<UniteAerienne *>(unite);
    if (ua && !getUniteAerienne())
        return true;

    auto um = dynamic_cast<UniteMarine *>(unite);
    if (um && !_uniteBasse)
        return true;

    return false;
}

void CaseMarine::deplacerUniteBasse(CaseMarine *arrivee, stat cout)
{
    _uniteBasse->utiliserProvisions(cout);
    arrivee->setUniteBasse(std::move(_uniteBasse));
}

std::vector<Unite *> CaseMarine::getUnites() const
{
    auto unites = Case::getUnites();
    if (_uniteBasse)
        unites.push_back(_uniteBasse.get());
    return unites;
}

void CaseMarine::deplacerUnite(std::size_t indUnite, Case *arrivee, stat cout)
{
    if (indUnite >= 2)
        throw std::invalid_argument("Erreur : Indice incorrecte");

    if (getUniteAerienne()) {
        if (indUnite == 0)
            Case::deplacerUniteAerienne(arrivee, cout);

        else {
            auto cm = dynamic_cast<CaseMarine *>(arrivee);
            if (!cm)
                throw std::invalid_argument("Erreur : Deplacement impossible vers une case terrestre");
            deplacerUniteBasse(cm, cout);
        }
    }

    else if (indUnite == 1)
        throw std::invalid_argument("Erreur : Indice incorrecte");

    else {
        auto cm = dynamic_cast<CaseMarine *>(arrivee);
        if (!cm)
            throw std::invalid_argument("Erreur : Deplacement impossible vers une case terrestre");
        deplacerUniteBasse(cm, cout);
    }
}

stat CaseMarine::coutDeplacement(Unite *unite) const
{
    if (peutAccueillir(unite))
        return 1;
    return std::numeric_limits<stat>::max();
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
}

std::size_t CaseMarine::nbUnites() const
{
    return Case::nbUnites() + (_uniteBasse ? 1 : 0);
}

std::set<indiceConstruction> CaseMarine::getIndicesConstructionsPossibles() const
{
    return {};  // aucune constructions possibles
}

void CaseMarine::supprimeNonUnitesOperationnelles()
{
    Case::supprimeNonUnitesOperationnelles();
    if (_uniteBasse && !_uniteBasse->estOperationnelle())
        _uniteBasse = nullptr;
}
