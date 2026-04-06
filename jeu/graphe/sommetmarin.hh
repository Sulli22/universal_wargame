#pragma once

#include "sommet.hh"
#include "unitemarine.hh"

class SommetMarin : public Sommet {
public:
    SommetMarin();

    std::shared_ptr<UniteMarine> getUniteBasse() const;
    void setUniteBasse(std::shared_ptr<UniteMarine> nvUniteBasse);

private:
    std::shared_ptr<UniteMarine> _uniteBasse;
};

