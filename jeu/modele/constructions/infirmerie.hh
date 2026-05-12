#pragma once

#include "construction.hh"

class Infirmerie : public ConstructionTemplate<Infirmerie> {
public:
    Infirmerie();

    static stat getCoutImpl();
    void effectuerEffet(Unite *unite) const override;
};

