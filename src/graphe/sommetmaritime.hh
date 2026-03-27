#pragma once

#include "sommet.hh"
#include "unitemaritime.hh"

class SommetMaritime : public Sommet {
public:
    SommetMaritime();

    std::shared_ptr<UniteMaritime> getUniteBasse() const;
    void setUniteBasse(std::shared_ptr<UniteMaritime> nvUniteBasse);

private:
    std::shared_ptr<UniteMaritime> _uniteBasse;
};

