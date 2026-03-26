#pragma once

#include "unite.hh"

class UniteLegere : public Unite
{
public:
    UniteLegere(unsigned int pointsVie,
                unsigned int nbMunitions);

    bool estLegere() const override;
    virtual unsigned int getTaille() const=0;
};
