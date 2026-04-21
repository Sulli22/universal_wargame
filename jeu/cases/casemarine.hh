#pragma once

#include "case.hh"
#include "unitemarine.hh"

class CaseMarine : public Case {
public:
    CaseMarine(const Position &pos);

    const UniteMarine *getUniteBasse() const;

    void setUniteBasse(std::unique_ptr<UniteMarine> nvUniteBasse);

    bool peutAccueillir(Unite *unite) const override;
    void deplacerUniteBasse(CaseMarine *arrivee, usint cout);
    std::vector<Unite *> getUnites() const override;
    void deplacerUnite(std::size_t indUnite, Case *arrivee, usint cout) override;
    usint coutDeplacement(Unite *unite) const override;
    Faction getFaction() const override;
    void afficherDetails(std::ostream &os) const override;
    usint nbUnites() const override;

private:
    std::unique_ptr<UniteMarine> _uniteBasse;
};

