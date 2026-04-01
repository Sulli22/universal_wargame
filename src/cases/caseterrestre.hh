#pragma once
#include <vector>
#include "case.hh"
#include "uniteterrestre.hh"
#include "construction.hh"

enum class typeTerrain {plaine, foret, montagne, riviere};

class CaseTerrestre : public Case
{
public:
    CaseTerrestre(const Position &pos, bool verifConstruction=false, usint espaceDisponible = _MAX_TAILLE, typeTerrain terrain = typeTerrain::plaine);

    std::vector<std::shared_ptr<UniteTerrestre>> getUniteBasse() const;
    usint getEspaceDisponible() const;
    Construction getConstruction() const;
    bool getVerifConstruction() const;
    typeTerrain getTerrain() const;

    void setConstruction(const Construction & nvConstrution);
    void setVerifConstruction(bool nvVerifConstruction);
    void setTerrain(typeTerrain nvTerrain);
    bool ajouterUniteTerrestre(std::shared_ptr<UniteTerrestre> nvUniteTerrestre);



private:
    std::vector<std::shared_ptr<UniteTerrestre>> _uniteBasse;
    Construction _construction;
    bool _verifConstruction;
    usint _espaceDisponible;
    typeTerrain _terrain;
    static const usint _MAX_TAILLE = 100;

};

