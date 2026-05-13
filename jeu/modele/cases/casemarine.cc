#include "casemarine.hh"

#include <limits>
#include "genie.hh"

CaseMarine::CaseMarine(const Position &pos):
    Case(pos)
{}

void CaseMarine::setUniteBasse(std::unique_ptr<UniteMarine> nvUniteBasse)
{
    if (_uniteBasse)
        throw std::runtime_error("Erreur : la place est deja occupee");

    if (!nvUniteBasse)
        throw std::invalid_argument("Erreur : une unite nulle ne peut pas etre ajoutee");

    if (getFaction() != Faction::neutre && nvUniteBasse->getFaction() != getFaction())
        throw std::invalid_argument("Erreur : une unite d'une autre faction ne peut pas etre ajoutee");

    _uniteBasse = std::move(nvUniteBasse);
}

void CaseMarine::deplacerUnite(std::size_t indUnite, Case *arrivee, Stat cout)
{
    if (indUnite >= 2)
        throw std::invalid_argument("Erreur : indice incorrecte");

    if (getUniteAerienne()) {
        if (indUnite == 0)
            Case::deplacerUniteAerienne(arrivee, cout);

        else {
            auto cm = dynamic_cast<CaseMarine *>(arrivee);
            if (!cm)
                throw std::invalid_argument("Erreur : deplacement impossible vers une case terrestre");
            deplacerUniteBasse(cm, cout);
        }
    }

    else if (indUnite == 1)
        throw std::invalid_argument("Erreur : indice incorrecte");

    else {
        auto cm = dynamic_cast<CaseMarine *>(arrivee);
        if (!cm)
            throw std::invalid_argument("Erreur : deplacement impossible vers une case terrestre");
        deplacerUniteBasse(cm, cout);
    }
}

void CaseMarine::supprimeNonUnitesOperationnelles()
{
    Case::supprimeNonUnitesOperationnelles();
    if (_uniteBasse && !_uniteBasse->estOperationnelle())
        _uniteBasse = nullptr;
}

std::vector<Unite *> CaseMarine::getUnites() const
{
    auto unites = Case::getUnites();
    if (_uniteBasse)
        unites.push_back(_uniteBasse.get());
    return unites;
}

std::size_t CaseMarine::nbUnites() const
{
    return Case::nbUnites() + (_uniteBasse ? 1 : 0);
}

Stat CaseMarine::coutDeplacement(Unite *unite) const
{
    return (peutAccueillir(unite)) ? 1 : std::numeric_limits<Stat>::max();
}

Faction CaseMarine::getFaction() const
{
    auto faction = Case::getFaction();

    if (faction != Faction::neutre)
        return faction;

    if (_uniteBasse)
        return _uniteBasse->getFaction();

    return Faction::neutre;
}
std::vector<IndiceConstruction> CaseMarine::getIndicesConstructionsPossibles(const Genie &genie) const
{
    static_cast<void>(genie);
    return {};  // aucune constructions possibles
}

void CaseMarine::afficherDetails(std::ostream &os) const
{
    Case::afficherDetails(os); os << std::endl;
    os << "Type = Eau" << std::endl;
}

void CaseMarine::deplacerUniteBasse(CaseMarine *arrivee, Stat cout)
{
    _uniteBasse->utiliserProvisions(cout);
    arrivee->setUniteBasse(std::move(_uniteBasse));
}

bool CaseMarine::peutAccueillir(Unite *unite) const
{
    auto ua = dynamic_cast<UniteAerienne *>(unite);
    if (ua && !getUniteAerienne())  // unite est aerienne et la place n'est pas prise
        return true;

    auto um = dynamic_cast<UniteMarine *>(unite);
    if (um && !_uniteBasse)         // unite est marine et la place n'est pas prise
        return true;

    return false;
}
