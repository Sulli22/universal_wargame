#pragma once

#include "construction.hh"

class DepotMunitions : public ConstructionTemplate<DepotMunitions> {
public:
    DepotMunitions();

    static Stat getCoutImpl();
    void effectuerEffet(Unite *unite) const override;
};

