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
                  stat espaceDisponible = _MAX_ESPACE);

    const std::vector<std::unique_ptr<UniteTerrestre>> &getUnitesTerrestres() const;
    stat getEspaceDisponible() const;
    typeTerrain getTerrain() const;
    Construction *getConstruction() const;

    void setConstruction(std::unique_ptr<Construction> nvConstruction);

    bool peutAccueillir(Unite *unite) const override;
    void ajouterUniteTerrestre(std::unique_ptr<UniteTerrestre> nvUniteTerrestre);
    std::vector<Unite *> getUnites() const override;
    void deplacerUnite(std::size_t indUnite, Case *arrivee, stat cout) override;
    stat coutDeplacement(Unite *unite) const override;
    Faction getFaction() const override;
    std::size_t nbUnites() const override;
    void effectuerActionConstruction();
    std::vector<indiceConstruction> getIndicesConstructionsPossibles(const Genie &genie) const override;
    void supprimeNonUnitesOperationnelles() override;

// sortie flux
    void afficherDetails(std::ostream &os) const override;

private:
    void deplacerUniteTerrestre(std::size_t indUnite, CaseTerrestre *arrivee, stat cout);

// attributs
    std::vector<std::unique_ptr<UniteTerrestre>> _unitesTerrestres;
    stat _espaceDisponible;
    typeTerrain _terrain;
    std::unique_ptr<Construction> _construction;

    static const stat _MAX_ESPACE = 5;
};

