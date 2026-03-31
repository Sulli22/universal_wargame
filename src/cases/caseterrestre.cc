#include "caseterrestre.hh"
#include "uniteterrestrelegere.hh"
CaseTerrestre::CaseTerrestre(const Position &pos, usint espaceDisponible):Case(pos), _espaceDisponible(espaceDisponible)
{

}


std::vector<std::shared_ptr<UniteTerrestre>> CaseTerrestre::getUniteBasse() const {
    return _uniteBasse;
}

usint CaseTerrestre::getEspaceDisponible() const {
    return _espaceDisponible;
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

