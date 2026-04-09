#include "caseterrestre.hh"
#include "unitemarine.hh"
#include "uniteterrestrelegere.hh"
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

const Construction &CaseTerrestre::getConstruction() const
{
   return *_construction;
}

typeTerrain CaseTerrestre::getTerrain() const
{
    return _terrain;
}

void CaseTerrestre::setConstruction(std::unique_ptr<Construction>
                                        nvConstruction)
{
    if (_construction) {
        if (_terrain == typeTerrain::riviere) {
            if (nvConstruction->estPont())
                _construction = std::move(nvConstruction);
            else
                throw std::runtime_error("Erreur : La case est une rivière.");
        }
        else if (!nvConstruction->estPont())
            _construction = std::move(nvConstruction);
        else
            throw std::invalid_argument("Erreur : La construction ne peut pas etre un pont");
    }
    else
       throw std::runtime_error("Erreur : La place est déja prise.");
}

bool CaseTerrestre::ajouterUniteTerrestre(std::unique_ptr<UniteTerrestre>
                                              nvUniteTerrestre)
{
    if (!nvUniteTerrestre)
        throw  std::invalid_argument("Erreur : une unite nulle ne peut pas être ajoutée");

    if (getFaction() != Faction::neutre &&
        nvUniteTerrestre->getFaction() != getFaction())
        throw std::invalid_argument("Erreur : La nouvelle unite n'appartient pas à la faction.");

    if (nvUniteTerrestre->estLegere()) {
        auto puniteTerrestre = dynamic_cast<UniteTerrestreLegere *>
            (nvUniteTerrestre.get());

        if (puniteTerrestre->getTaille() >= _espaceDisponible) {
            _unitesTerrestres.push_back(std::move(nvUniteTerrestre));
            _espaceDisponible -= puniteTerrestre->getTaille();
            return true;
        }
    }
    else if (_espaceDisponible == _MAX_TAILLE) {
        _unitesTerrestres.push_back(std::move(nvUniteTerrestre));
        _espaceDisponible = 0;
        return true;
    }
    return false;
}
/*
void CaseTerrestre::deplacerUnitesTerrestres(CaseTerrestre &arrivee)
{
    if (_MAX_TAILLE - _espaceDisponible <= arrivee.getEspaceDisponible()) {
        for (auto u : _unitesTerrestres) {
            arrivee.ajouterUniteTerrestre(u);
            _unitesTerrestres.clear();
        }
    }
    else
        throw "Il n'y a pas assez d'espaces disponible";
}
*/
usint CaseTerrestre::coutDeplacement(Unite *unite) const
{
    auto pUniteAerienne = dynamic_cast<UniteAerienne *>(unite);
    if (pUniteAerienne)
        return 1;

    auto pUniteMarine = dynamic_cast<UniteMarine *>(unite);
    auto inf = std::numeric_limits<usint>::infinity();
    if (pUniteMarine)
        return inf;

    switch (_terrain) {
        case typeTerrain::plaine:
            return 1;
        case typeTerrain::foret:
            return unite->estLegere() ? 1 : 2;
        case typeTerrain::riviere:
            return inf;
        case typeTerrain::montagne:
            return inf;
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

    for (const auto &unite : _unitesTerrestres) {
        os << "Unite = [";
        unite ->sortieFlux(os);
        os << "]" << std::endl;
    }
}
