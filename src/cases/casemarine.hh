#pragma once

#include "case.hh"
#include "unitemarine.hh"

class CaseMarine : public Case
{
public:
    CaseMarine(const Position &pos);

    std::shared_ptr<UniteMarine> getUniteBasse() const;
    void setUniteBasse(std::shared_ptr<UniteMarine> nvUniteBasse);
private:
    std::shared_ptr<UniteMarine> _uniteBasse;
};

