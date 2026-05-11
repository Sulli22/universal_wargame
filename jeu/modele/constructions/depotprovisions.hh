#pragma once

#include "construction.hh"

class DepotProvisions : public ConstructionTemplate<DepotProvisions> {
public:
    DepotProvisions();

    static stat getCoutImpl();

    void  effectuerAction(Unite *unite) const override;
};

