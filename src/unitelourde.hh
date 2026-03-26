#pragma once

#include "unite.hh"

class UniteLourde : public Unite {
public:
    UniteLourde(unsigned int pointsVie,
                unsigned int nbMunitions,
                unsigned int pointsBouclier);

    unsigned int getPointsBouclier() const;

    bool estLegere() const override;
    void prendreDegats(unsigned int degats) override;

private:
    unsigned int _pointsBouclier;
};
