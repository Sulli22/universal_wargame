#pragma once

#include "case.hh"
#include "unitemarine.hh"

class CaseMarine : public Case {
public:
    CaseMarine(const Position &pos);

// méthodes jeu
    void setUniteBasse(std::unique_ptr<UniteMarine> nvUniteBasse);
    void deplacerUnite(std::size_t indUnite, Case *arrivee, Stat cout) override;
    void supprimeNonUnitesOperationnelles() override;

    std::vector<Unite *> getUnites() const override;
    std::size_t nbUnites() const override;
    Stat coutDeplacement(Unite *unite) const override;
    Faction getFaction() const override;
    std::vector<IndiceConstruction> getIndicesConstructionsPossibles(const Genie &genie) const override;

// sortie flux
    void afficherDetails(std::ostream &os) const override;

private:
    void deplacerUniteBasse(CaseMarine *arrivee, Stat cout);
    bool peutAccueillir(Unite *unite) const override;

// attribut
    std::unique_ptr<UniteMarine> _uniteBasse;
};

