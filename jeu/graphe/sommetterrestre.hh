#pragma once

#include <vector>
#include "sommet.hh"
#include "uniteterrestre.hh"

class SommetTerrestre : public Sommet {
public:
    SommetTerrestre(usint espaceDisponible = _MAX_TAILLE);
    std::vector<std::shared_ptr<UniteTerrestre>> getUniteBasse() const;
    usint getEspaceDisponible() const;
    bool ajouterUniteTerrestre(std::shared_ptr<UniteTerrestre> nvUniteTerrestre);

private:
    std::vector<std::shared_ptr<UniteTerrestre>> _uniteBasse;
    usint _espaceDisponible;
    static const usint _MAX_TAILLE = 100;
};

