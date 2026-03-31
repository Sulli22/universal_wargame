#include "caseterrestre.hh"
#include "uniteterrestrelegere.hh"
CaseTerrestre::CaseTerrestre(const Position &pos,bool verifConstruction, usint espaceDisponible):Case(pos),_verifConstruction(verifConstruction), _espaceDisponible(espaceDisponible)
{

}


std::vector<std::shared_ptr<UniteTerrestre>> CaseTerrestre::getUniteBasse() const {
    return _uniteBasse;
}

usint CaseTerrestre::getEspaceDisponible() const {
    return _espaceDisponible;
}

Construction CaseTerrestre::getConstruction() const {
    if (_verifConstruction) {
        return _construction;
    }
   // throw "Pas de constructions";
}

bool CaseTerrestre::getVerifConstruction() const {
    return _verifConstruction;
}

void CaseTerrestre::setConstruction(const Construction & nvConstruction) {
    if (!_verifConstruction) {
        _construction = nvConstruction;
    }
    else {
        //throw "Déjà une construction";
    }
}

void CaseTerrestre::setVerifConstruction(bool nvVerifConstruction) {
    _verifConstruction = nvVerifConstruction;
}

bool CaseTerrestre::ajouterUniteTerrestre(std::shared_ptr<UniteTerrestre> nvUniteTerrestre) {
    if (nvUniteTerrestre->estLegere()) {
        auto uniteTerrestre = std::dynamic_pointer_cast<UniteTerrestreLegere>(nvUniteTerrestre);
        if (uniteTerrestre->getTaille() >= _espaceDisponible) {
            _uniteBasse.push_back(nvUniteTerrestre);
            _espaceDisponible -= uniteTerrestre->getTaille();
            return true;
        }
    }
    else {
        if (_espaceDisponible == _MAX_TAILLE) {
            _uniteBasse.push_back(nvUniteTerrestre);
            _espaceDisponible = 0;
            return true;
        }
    }

    return false;
}

