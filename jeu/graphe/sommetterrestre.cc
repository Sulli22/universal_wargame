#include "sommetterrestre.hh"

SommetTerrestre::SommetTerrestre(usint espaceDisponible):_espaceDisponible(espaceDisponible)
{}

std::vector<std::shared_ptr<UniteTerrestre>> SommetTerrestre::getUniteBasse() const {
    return _uniteBasse;
}

usint SommetTerrestre::getEspaceDisponible() const {
    return _espaceDisponible;
}

/*
bool SommetTerrestre::ajouterUniteTerrestre(std::shared_ptr<UniteTerrestre> nvUniteTerrestre) {
    if (nvUniteTerrestre->getTaille() >= _espaceDisponible) {
        _uniteBasse.push_back(nvUniteTerrestre);
        _espaceDisponible -= nvUniteTerrestre->getTaille();
        return true;
    }
    return false;
}
*/
