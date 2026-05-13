#pragma once

#include <vector>
#include "case.hh"
#include "uniteterrestre.hh"
#include "construction.hh"

enum class TypeTerrain { plaine, foret, montagne, riviere };

class CaseTerrestre : public Case {
public:
    CaseTerrestre(const Position &pos,
                  TypeTerrain terrain = TypeTerrain::plaine,
                  Stat espaceDisponible = _MAX_ESPACE);

// getters
    TypeTerrain getTerrain() const;
    Construction *getConstruction() const;

// méthodes jeu
    void deplacerUnite(std::size_t indUnite, Case *arrivee, Stat cout) override;
    void supprimeNonUnitesOperationnelles() override;
    void ajouterUniteTerrestre(std::unique_ptr<UniteTerrestre> nvUniteTerrestre);
    void setConstruction(std::unique_ptr<Construction> nvConstruction);
    void effectuerEffetConstruction();

    std::vector<Unite *> getUnites() const override;
    std::size_t nbUnites() const override;
    Stat coutDeplacement(Unite *unite) const override;
    Faction getFaction() const override;
    std::vector<IndiceConstruction> getIndicesConstructionsPossibles(const Genie &genie) const override;

// sortie flux
    void afficherDetails(std::ostream &os) const override;

private:
    bool peutAccueillir(Unite *unite) const override;
    void deplacerUniteTerrestre(std::size_t indUnite, CaseTerrestre *arrivee, Stat cout);

// attributs
    std::vector<std::unique_ptr<UniteTerrestre>> _unitesTerrestres;
    Stat _espaceDisponible;
    TypeTerrain _terrain;
    std::unique_ptr<Construction> _construction;

    static const Stat _MAX_ESPACE = 5;
};

