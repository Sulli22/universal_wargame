#pragma once

#include "construction.hh"

class DepotProvisions : public Construction {
public:
    DepotProvisions();

    void  effectuerAction(Unite *unite) const override;
};

