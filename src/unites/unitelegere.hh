#pragma once

#include "unite.hh"

class UniteLegere : public Unite {
public:
    UniteLegere(usint pointsVie, usint nbMunitions, usint nbProvisions);

    bool estLegere() const override;
    void sortieFlux(std::ostream &os) const override;
    virtual usint getTaille() const =0;
};
