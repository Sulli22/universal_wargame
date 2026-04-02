#pragma once

#include <vector>
#include "case.hh"
#include "uniteterrestre.hh"
#include "construction.hh"

enum class typeTerrain { plaine, foret, montagne, riviere };

class CaseTerrestre : public Case {
public:
    CaseTerrestre(const Position &pos, usint espaceDisponible = _MAX_TAILLE,
                  typeTerrain terrain = typeTerrain::plaine);

    std::vector<std::shared_ptr<UniteTerrestre>> getUnitesTerrestres() const;
    usint getEspaceDisponible() const;
    const std::unique_ptr<Construction> &getConstruction() const;
    typeTerrain getTerrain() const;

    void setConstruction(std::unique_ptr<Construction> nvConstruction);
    bool ajouterUniteTerrestre(std::shared_ptr<UniteTerrestre> nvUniteTerrestre);

private:
    std::vector<std::shared_ptr<UniteTerrestre>> _unitesTerrestres;
    usint _espaceDisponible;
    typeTerrain _terrain;
    std::unique_ptr<Construction> _construction;

    static const usint _MAX_TAILLE = 5;
};

