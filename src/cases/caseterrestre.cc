#include "caseterrestre.hh"
#include "uniteterrestrelegere.hh"

CaseTerrestre::CaseTerrestre(const Position &pos, usint espaceDisponible,
                             typeTerrain terrain):
    Case(pos), _verifConstruction(false),
    _espaceDisponible(espaceDisponible), _terrain(terrain)
{}

std::vector<std::shared_ptr<UniteTerrestre>> CaseTerrestre::getUniteBasse() const
{
    return _unitesTerrestres;
}

usint CaseTerrestre::getEspaceDisponible() const
{
    return _espaceDisponible;
}

Construction CaseTerrestre::getConstruction() const
{
    if (_verifConstruction)
        return _construction;
    throw "Pas de constructions";
}

bool CaseTerrestre::getVerifConstruction() const
{
    return _verifConstruction;
}

typeTerrain CaseTerrestre::getTerrain() const
{
    return _terrain;
}

void CaseTerrestre::setConstruction(const Construction & nvConstruction)
{
    if (!_verifConstruction) {
        if (_terrain == typeTerrain::riviere) {
            if (nvConstruction.estPont())
                _construction = nvConstruction;
            else
                throw "La case est une rivière";
        }
        else if (!nvConstruction.estPont())
            _construction = nvConstruction;
        else
            throw "La construction ne peut pas être un pont";
    }
    else
       throw "Déjà une construction";
}

void CaseTerrestre::setVerifConstruction(bool nvVerifConstruction)
{
    _verifConstruction = nvVerifConstruction;
}

bool CaseTerrestre::ajouterUniteTerrestre(std::shared_ptr<UniteTerrestre> nvUniteTerrestre)
{
    if (nvUniteTerrestre->estLegere()) {
        auto uniteTerrestre = std::dynamic_pointer_cast<UniteTerrestreLegere>(nvUniteTerrestre);
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

