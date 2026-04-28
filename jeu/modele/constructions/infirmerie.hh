#pragma once

#include "construction.hh"

class Infirmerie : public Construction {
public:
    Infirmerie();

    void effectuerAction(Unite *unite) const override;
};

