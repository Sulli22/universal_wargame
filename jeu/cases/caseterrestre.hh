#pragma once

#include <vector>
#include "case.hh"
#include "uniteterrestre.hh"
#include "construction.hh"

enum class typeTerrain { plaine, foret, montagne, riviere };

class CaseTerrestre : public Case {
public:
    CaseTerrestre(const Position &pos,
                  typeTerrain terrain = typeTerrain::plaine,
                  usint espaceDisponible = _MAX_TAILLE);

    const std::vector<std::unique_ptr<UniteTerrestre>>&getUnitesTerrestres() const;
    usint getEspaceDisponible() const;
    typeTerrain getTerrain() const;
    const Construction &getConstruction() const;

    void setConstruction(std::unique_ptr<Construction> nvConstruction);

    void ajouterUniteTerrestre(std::unique_ptr<UniteTerrestre> nvUniteTerrestre);
    void deplacerUniteTerrestre(std::size_t indUnite, CaseTerrestre *arrivee);
    std::vector<Unite *> getUnites() const override;
    void deplacerUnite(std::size_t indUnite, Case *arrivee) override;
    usint coutDeplacement(Unite *unite) const override;
    Faction getFaction() const override;
    void afficherDetails(std::ostream &os) const override;

private:
    std::vector<std::unique_ptr<UniteTerrestre>> _unitesTerrestres;
    usint _espaceDisponible;
    typeTerrain _terrain;
    std::unique_ptr<Construction> _construction;

    static const usint _MAX_TAILLE = 5;
};

