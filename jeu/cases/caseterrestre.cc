#include "caseterrestre.hh"
#include "unitemarine.hh"
#include "uniteterrestrelegere.hh"
#include "uniteterrestrelourde.hh"
#include <limits>

CaseTerrestre::CaseTerrestre(const Position &pos, typeTerrain terrain,
                             usint espaceDisponible):
    Case(pos), _espaceDisponible(espaceDisponible), _terrain(terrain)
{}

const std::vector<std::unique_ptr<UniteTerrestre>>
    &CaseTerrestre::getUnitesTerrestres() const
{
    return _unitesTerrestres;
}

usint CaseTerrestre::getEspaceDisponible() const
{
    return _espaceDisponible;
}

const Construction *CaseTerrestre::getConstruction() const
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
        throw std::runtime_error("Erreur : La place est déja prise");

    if (_terrain == typeTerrain::riviere) {
        if (nvConstruction->estPont())
            _construction = std::move(nvConstruction);
        else
            throw std::runtime_error("Erreur : La case est une rivière");
    }

    else if (_terrain != typeTerrain::plaine)
        throw std::runtime_error("Erreur : Ce type de case n'est pas constructible");

    if (nvConstruction->estPont())
        throw std::invalid_argument("Erreur : La construction ne peut pas etre un pont");

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
    if (utLourde && (_espaceDisponible == _MAX_TAILLE))
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
        auto uniteTerrestreLeg = dynamic_cast<UniteTerrestreLegere *>
            (nvUniteTerrestre.get());

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
    else if (_espaceDisponible == _MAX_TAILLE) {
        _unitesTerrestres.push_back(std::move(nvUniteTerrestre));
        _espaceDisponible = 0;
    }
    else
        throw std::runtime_error("Erreur : Ajout impossible, place est insufisante (toute la place est necessaire pour une unite lourde)");
}

void CaseTerrestre::deplacerUniteTerrestre(std::size_t indUnite, CaseTerrestre *arrivee)
{
    if (_unitesTerrestres.at(indUnite)->estLegere()) {
        auto uniteTerrestreLeg = dynamic_cast<UniteTerrestreLegere *>
            (_unitesTerrestres.at(indUnite).get());
        _espaceDisponible += uniteTerrestreLeg->getTaille();
    }
    else
        _espaceDisponible = _MAX_TAILLE;
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

void CaseTerrestre::deplacerUnite(std::size_t indUnite, Case *arrivee)
{
    if (indUnite == 0)
        Case::deplacerUniteAerienne(arrivee);
    else {
        auto ct = dynamic_cast<CaseTerrestre *>(arrivee);
        deplacerUniteTerrestre(indUnite-1, ct);
    }
}

usint CaseTerrestre::coutDeplacement(Unite *unite) const
{
    auto max = std::numeric_limits<usint>::max();
    if (!peutAccueillir(unite))
        return max;

    auto pUniteAerienne = dynamic_cast<UniteAerienne *>(unite);
    if (pUniteAerienne)
        return 1;

    auto pUniteMarine = dynamic_cast<UniteMarine *>(unite);
    if (pUniteMarine)
        return max;

    switch (_terrain) {
        case typeTerrain::plaine:
            return 1;
        case typeTerrain::foret:
            return unite->estLegere() ? 1 : 2;
        case typeTerrain::riviere:
            return max;
        case typeTerrain::montagne:
            return max;
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

void CaseTerrestre::effectuerActionConstruction()
{
    if (!_construction)
        throw std::runtime_error("Erreur : aucune construction");

    _construction->effectuerAction(getUnites());
}

void CaseTerrestre::afficherDetails(std::ostream &os) const
{
    Case::afficherDetails(os); os << std::endl;

    os << "Type = ";
    switch (_terrain) {
        case typeTerrain::plaine: os << "Plaine"; break;
        case typeTerrain::foret: os << "Foret"; break;
        case typeTerrain::riviere: os << "Riviere"; break;
        case typeTerrain::montagne: os << "Montagne"; break;
    }
    os << std::endl;

    os << "Espace dispo = " << _espaceDisponible << std::endl;
}
