#pragma once
#include <vector>
#include "case.hh"
#include "uniteterrestre.hh"
#include "construction.hh"
class CaseTerrestre : public Case
{
public:
    CaseTerrestre(const Position &pos, bool verifConstruction=false, usint espaceDisponible = _MAX_TAILLE);
    std::vector<std::shared_ptr<UniteTerrestre>> getUniteBasse() const;
    usint getEspaceDisponible() const;
    Construction getConstruction() const;
    bool getVerifConstruction() const;

    void setConstruction(const Construction & nvConstrution);
    void setVerifConstruction(bool nvVerifConstruction);
    bool ajouterUniteTerrestre(std::shared_ptr<UniteTerrestre> nvUniteTerrestre);



private:
    std::vector<std::shared_ptr<UniteTerrestre>> _uniteBasse;
    Construction _construction;
    bool _verifConstruction;
    usint _espaceDisponible;
    static const usint _MAX_TAILLE = 100;

};

