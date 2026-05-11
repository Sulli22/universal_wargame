#pragma once

#include "construction.hh"

class DepotMunitions : public ConstructionTemplate<DepotMunitions> {
public:
    DepotMunitions();

    static stat getCoutImpl();

    void effectuerAction(Unite *unite) const override;
};

