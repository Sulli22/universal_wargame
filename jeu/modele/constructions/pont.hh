#pragma once

#include "construction.hh"

class Pont : public ConstructionTemplate<Pont> {
public:
    Pont();

    static stat getCoutImpl();
    bool estPont() const override;
    void effectuerEffet(Unite *unite) const override;
};

