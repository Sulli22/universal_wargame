#pragma once

#include "unite.hh"

class UniteLegere : public Unite
{
public:
    UniteLegere(usint pointsVie, usint nbMunitions);

    bool estLegere() const override;
    virtual usint getTaille() const=0;
};
