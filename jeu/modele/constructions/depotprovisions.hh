#pragma once

#include "construction.hh"

class DepotProvisions : public ConstructionTemplate<DepotProvisions> {
public:
    DepotProvisions();

    static Stat getCoutImpl();
    void  effectuerEffet(Unite *unite) const override;
};

