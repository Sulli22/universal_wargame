#pragma once

#include "case.hh"
#include "unitemarine.hh"

class CaseMarine : public Case {
public:
    CaseMarine(const Position &pos);

    const UniteMarine *getUniteBasse() const;

    void setUniteBasse(std::unique_ptr<UniteMarine> nvUniteBasse);

    std::vector<Unite *> getUnites() const override;
    void deplacerUnite(std::size_t indUnite, Case *arrivee, stat cout) override;
    stat coutDeplacement(Unite *unite) const override;
    Faction getFaction() const override;
    std::size_t nbUnites() const override;
    std::vector<indiceConstruction> getIndicesConstructionsPossibles(const Genie &genie) const override;
    void supprimeNonUnitesOperationnelles() override;

// sortie flux
    void afficherDetails(std::ostream &os) const override;

private:
    void deplacerUniteBasse(CaseMarine *arrivee, stat cout);
    bool peutAccueillir(Unite *unite) const override;

// attribut
    std::unique_ptr<UniteMarine> _uniteBasse;
};

