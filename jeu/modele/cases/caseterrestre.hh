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
                  uint16_t espaceDisponible = _MAX_TAILLE);

    const std::vector<std::unique_ptr<UniteTerrestre>> &getUnitesTerrestres() const;
    uint16_t getEspaceDisponible() const;
    typeTerrain getTerrain() const;
    const Construction *getConstruction() const;

    void setConstruction(std::unique_ptr<Construction> nvConstruction);

    bool peutAccueillir(Unite *unite) const override;
    void ajouterUniteTerrestre(std::unique_ptr<UniteTerrestre> nvUniteTerrestre);
    std::vector<Unite *> getUnites() const override;
    void deplacerUnite(std::size_t indUnite, Case *arrivee, uint16_t cout) override;
    uint16_t coutDeplacement(Unite *unite) const override;
    Faction getFaction() const override;
    uint16_t nbUnites() const override;
    void effectuerActionConstruction();
    uint16_t nbConstructionsPossibles() const override;
    void supprimeNonUnitesOperationnelles() override;

// sortie flux
    void afficherDetails(std::ostream &os) const override;

private:
    void deplacerUniteTerrestre(std::size_t indUnite, CaseTerrestre *arrivee, uint16_t cout);

// attributs
    std::vector<std::unique_ptr<UniteTerrestre>> _unitesTerrestres;
    uint16_t _espaceDisponible;
    typeTerrain _terrain;
    std::unique_ptr<Construction> _construction;

    static const uint16_t _MAX_TAILLE = 5;
};

