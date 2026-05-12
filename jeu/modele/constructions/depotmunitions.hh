#pragma once

#include "construction.hh"

class DepotMunitions : public ConstructionTemplate<DepotMunitions> {
public:
    DepotMunitions();

    static stat getCoutImpl();
    void effectuerEffet(Unite *unite) const override;
};

