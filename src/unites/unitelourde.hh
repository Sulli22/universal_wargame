#pragma once

#include "unite.hh"

class UniteLourde : public Unite {
public:
    UniteLourde(usint pointsVie, usint nbMunitions, usint pointsBouclier);

    usint getPointsBouclier() const;

    bool estLegere() const override;
    void prendreDegats(usint degats) override;

private:
    usint _pointsBouclier;
};
