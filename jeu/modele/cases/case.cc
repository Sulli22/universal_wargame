#include "case.hh"
#include <iostream>

Case::Case(const Position &pos) :
    _pos(pos)
{}

const Position &Case::getPos() const
{
    return _pos;
}

const UniteAerienne *Case::getUniteAerienne() const
{
    return _uniteAerienne.get();
}

void Case::setUniteAerienne(std::unique_ptr<UniteAerienne> nvUniteAerienne)
{
    if (_uniteAerienne)
        throw std::runtime_error("Erreur : La place est deja occupee.");

    if (!nvUniteAerienne)
        throw std::invalid_argument("Erreur : Une unite nulle ne peut pas etre ajoutee.");

    _uniteAerienne = std::move(nvUniteAerienne);
}

void Case::deplacerUniteAerienne(Case *arrive, uint16_t cout)
{
    _uniteAerienne->utiliserProvisions(cout);
    arrive->setUniteAerienne(std::move(_uniteAerienne));
}

Unite *Case::getUnite(std::size_t indUnite)
{
    return getUnites().at(indUnite);
}

std::vector<Unite *> Case::getUnites() const
{
    std::vector<Unite *> unites;
    if (_uniteAerienne)
        unites.push_back(_uniteAerienne.get());
    return unites;
}

Faction Case::getFaction() const
{
    return _uniteAerienne ? _uniteAerienne->getFaction() : Faction::neutre;
}

uint16_t Case::nbUnites() const
{
    return _uniteAerienne ? 1 : 0;
}

bool Case::estConstructible() const
{
    return nbConstructionsPossibles() > 0;
}

void Case::supprimeNonUnitesOperationnelles()
{
    if (_uniteAerienne && !_uniteAerienne->estOperationnelle())
        _uniteAerienne = nullptr;
}

void Case::sortieFlux(std::ostream &os) const
{
    _pos.sortieFlux(os);
}

void Case::afficherDetails(std::ostream &os) const
{
    os << "-> Case : "; sortieFlux(os);

    auto unites = getUnites();
    for (std::size_t i = 0; i < unites.size(); ++i) {
        os << std::endl << "Unite " << i << " = [";
        unites[i]->sortieFlux(os);
        os << "]";
    }
}
