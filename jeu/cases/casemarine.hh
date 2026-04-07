#pragma once

#include "case.hh"
#include "unitemarine.hh"

class CaseMarine : public Case {
public:
    CaseMarine(const Position &pos);

    const UniteMarine *getUniteBasse() const;

    void setUniteBasse(std::unique_ptr<UniteMarine> nvUniteBasse);

    void deplacerUniteBasse(CaseMarine &arrive);

    usint coutDeplacement(Unite *unite) const override;
    void afficherDetails(std::ostream &os) const override;

private:
    std::unique_ptr<UniteMarine> _uniteBasse;
};

