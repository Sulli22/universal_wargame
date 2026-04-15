#pragma once

#include "construction.hh"

class DepotMunitions : public Construction {
public:
    DepotMunitions();

    void effectuerAction(Unite *unite) const override;
};

