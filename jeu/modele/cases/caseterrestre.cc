#include "caseterrestre.hh"

#include "unitemarine.hh"
#include "uniteterrestrelegere.hh"
#include "uniteterrestrelourde.hh"
#include "genie.hh"
#include "depotmunitions.hh"
#include "depotprovisions.hh"
#include "infirmerie.hh"
#include "pont.hh"

#include <iostream>
#include <limits>

CaseTerrestre::CaseTerrestre(const Position &pos, typeTerrain terrain,
                             stat espaceDisponible):
    Case(pos), _espaceDisponible(espaceDisponible), _terrain(terrain)
{}

const std::vector<std::unique_ptr<UniteTerrestre>>
    &CaseTerrestre::getUnitesTerrestres() const
{
    return _unitesTerrestres;
}

stat CaseTerrestre::getEspaceDisponible() const
{
    return _espaceDisponible;
}

Construction *CaseTerrestre::getConstruction() const
{
   return _construction.get();
}

typeTerrain CaseTerrestre::getTerrain() const
{
    return _terrain;
}

void CaseTerrestre::setConstruction(std::unique_ptr<Construction> nvConstruction)
{
    if (_construction)
        throw std::runtime_error("Erreur : la place est déja prise");

    if (_terrain == typeTerrain::riviere) {
        if (nvConstruction->estPont())
            _construction = std::move(nvConstruction);
        else
            throw std::runtime_error("Erreur : la case est une rivière");
    }

    else if (_terrain != typeTerrain::plaine)
        throw std::runtime_error("Erreur : ce type de case n'est pas constructible");

    else if (nvConstruction->estPont())
        throw std::invalid_argument("Erreur : la construction ne peut pas etre un pont");

    else
        _construction = std::move(nvConstruction);
}

bool CaseTerrestre::peutAccueillir(Unite *unite) const
{
    auto ua = dynamic_cast<UniteAerienne *>(unite);
    if (ua && !getUniteAerienne())
        return true;

    auto utLeg = dynamic_cast<UniteTerrestreLegere *>(unite);
    if (utLeg && (_espaceDisponible >= utLeg->getTaille()))
        return true;

    auto utLourde = dynamic_cast<UniteTerrestreLourde *>(unite);
    if (utLourde && (_espaceDisponible == _MAX_ESPACE))
        return true;

    return false;
}

void CaseTerrestre::ajouterUniteTerrestre(std::unique_ptr<UniteTerrestre>
                                              nvUniteTerrestre)
{
    if (!nvUniteTerrestre)
        throw  std::invalid_argument("Erreur : une unite nulle ne peut pas être ajoutée");

    if (getFaction() != Faction::neutre &&
        nvUniteTerrestre->getFaction() != getFaction())
        throw std::invalid_argument("Erreur : La nouvelle unite n'appartient pas à la faction.");

    if (nvUniteTerrestre->estLegere()) {
        auto uniteTerrestreLeg = dynamic_cast<UniteTerrestreLegere *>(nvUniteTerrestre.get());

        if (uniteTerrestreLeg->getTaille() <= _espaceDisponible) {
            if (_terrain == typeTerrain::foret)
                nvUniteTerrestre->setVisibilite(Unite::Visibilite::partielle);
            else
                nvUniteTerrestre->setVisibilite(Unite::Visibilite::totale);
            _unitesTerrestres.push_back(std::move(nvUniteTerrestre));
            _espaceDisponible -= uniteTerrestreLeg->getTaille();
        }

        else
            throw std::runtime_error("Erreur : Ajout impossible, place est insufisante");
    }

    else if (_espaceDisponible == _MAX_ESPACE) {
        _unitesTerrestres.push_back(std::move(nvUniteTerrestre));
        _espaceDisponible = 0;
    }

    else
        throw std::runtime_error("Erreur : Ajout impossible, place est insufisante (toute la place est necessaire pour une unite lourde)");
}

void CaseTerrestre::deplacerUniteTerrestre(std::size_t indUnite, CaseTerrestre *arrivee, stat cout)
{
    if (_unitesTerrestres.at(indUnite)->estLegere()) {
        auto uniteTerrestreLeg = dynamic_cast<UniteTerrestreLegere *>
            (_unitesTerrestres.at(indUnite).get());
        _espaceDisponible += uniteTerrestreLeg->getTaille();
    }

    else
        _espaceDisponible = _MAX_ESPACE;

    _unitesTerrestres.at(indUnite)->utiliserProvisions(cout);
    arrivee->ajouterUniteTerrestre(std::move(_unitesTerrestres.at(indUnite)));
    _unitesTerrestres.erase(_unitesTerrestres.begin() + indUnite);
}

std::vector<Unite *> CaseTerrestre::getUnites() const
{
    auto unites = Case::getUnites();
    for (auto &u : _unitesTerrestres)
        unites.push_back(u.get());
    return unites;
}

void CaseTerrestre::deplacerUnite(std::size_t indUnite, Case *arrivee, stat cout)
{
    bool indUniteZero = (indUnite == 0);

    if (indUniteZero && getUniteAerienne())
        Case::deplacerUniteAerienne(arrivee, cout);

    else {
        auto ct = dynamic_cast<CaseTerrestre *>(arrivee);
        auto dec = indUniteZero ? 0 : 1;
        deplacerUniteTerrestre(indUnite-dec, ct, cout);
    }
}

stat CaseTerrestre::coutDeplacement(Unite *unite) const
{
    auto max = std::numeric_limits<stat>::max();
    if (!peutAccueillir(unite))
        return max;

    auto pUniteAerienne = dynamic_cast<UniteAerienne *>(unite);
    if (pUniteAerienne)
        return 1;

    auto pUniteMarine = dynamic_cast<UniteMarine *>(unite);
    if (pUniteMarine)
        return max;

    switch (_terrain) {
    case typeTerrain::plaine:   return 1;
    case typeTerrain::foret:    return unite->estLegere() ? 1 : 2;
    case typeTerrain::riviere:  return _construction && _construction->estPont() ? 1 : max;
    case typeTerrain::montagne: return max;

    default:
        throw std::runtime_error("Erreur : Impossible de calculer le cout de deplacement");
    }
}

Faction CaseTerrestre::getFaction() const
{
    auto faction = Case::getFaction();
    if (faction != Faction::neutre) return faction;
    if (!_unitesTerrestres.empty()) return _unitesTerrestres[0]->getFaction();
    return Faction::neutre;
}

std::size_t CaseTerrestre::nbUnites() const
{
    return Case::nbUnites() + _unitesTerrestres.size();
}

void CaseTerrestre::effectuerActionConstruction()
{
    if (_construction)
        _construction->effectuerAction(getUnites());
}

std::vector<indiceConstruction> CaseTerrestre::getIndicesConstructionsPossibles(const Genie &genie) const
{
    if (_construction
        || _terrain == typeTerrain::foret
        || _terrain == typeTerrain::montagne)
        return {};   // rien ne peut etre construit

    if (_terrain == typeTerrain::riviere) {
        if (genie.peutDepenser(Pont::getCoutStatic()))
            return {3}; // pont uniquement
        return {};
    }

    // sinon on vérfie seulement le cout
    std::vector<indiceConstruction> res;

    if (genie.peutDepenser(DepotMunitions::getCoutStatic()))
        res.push_back(0);

    if (genie.peutDepenser(DepotProvisions::getCoutStatic()))
        res.push_back(1);

    if (genie.peutDepenser(Infirmerie::getCoutStatic()))
        res.push_back(2);

    return res;
}

void CaseTerrestre::supprimeNonUnitesOperationnelles()
{
    Case::supprimeNonUnitesOperationnelles();
    for (auto it = _unitesTerrestres.begin(); it != _unitesTerrestres.end(); ) {
        if (!(*it)->estOperationnelle())
            it = _unitesTerrestres.erase(it);
        else
            ++it;
    }
}

void CaseTerrestre::afficherDetails(std::ostream &os) const
{
    Case::afficherDetails(os); os << std::endl;

    os << "Type = ";
    switch (_terrain) {
    case typeTerrain::plaine:   os << "Plaine";     break;
    case typeTerrain::foret:    os << "Foret";      break;
    case typeTerrain::riviere:  os << "Riviere";    break;
    case typeTerrain::montagne: os << "Montagne";   break;
    }
    os << std::endl;

    os << "Espace dispo = " << _espaceDisponible << std::endl;

    os <<  "Construction ? " << (_construction != nullptr) << std::endl;
}
