#include "caseterrestre.hh"
#include "uniteterrestrelegere.hh"

CaseTerrestre::CaseTerrestre(const Position &pos, usint espaceDisponible,
                             typeTerrain terrain):
    Case(pos), _espaceDisponible(espaceDisponible), _terrain(terrain)
{}

std::vector<std::shared_ptr<UniteTerrestre>>
CaseTerrestre::getUnitesTerrestres() const
{
    return _unitesTerrestres;
}

usint CaseTerrestre::getEspaceDisponible() const
{
    return _espaceDisponible;
}

const std::unique_ptr<Construction> &CaseTerrestre::getConstruction() const
{
   return _construction;
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
                throw "La case est une rivière";
        }
        else if (!nvConstruction->estPont())
            _construction = std::move(nvConstruction);
        else
            throw "La construction ne peut pas être un pont";
    }
    else
       throw "Déjà une construction";
}

bool CaseTerrestre::ajouterUniteTerrestre(std::shared_ptr<UniteTerrestre>
                                              nvUniteTerrestre)
{
    if (nvUniteTerrestre->estLegere()) {
        auto uniteTerrestre = std::dynamic_pointer_cast<UniteTerrestreLegere>
            (nvUniteTerrestre);

        if (uniteTerrestre->getTaille() >= _espaceDisponible) {
            _unitesTerrestres.push_back(nvUniteTerrestre);
            _espaceDisponible -= uniteTerrestre->getTaille();
            return true;
        }
    }
    else if (_espaceDisponible == _MAX_TAILLE) {
        _unitesTerrestres.push_back(nvUniteTerrestre);
        _espaceDisponible = 0;
        return true;
    }
    return false;
}

