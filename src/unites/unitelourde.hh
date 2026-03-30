#pragma once

#include "unite.hh"

class UniteLourde : virtual public Unite {
public:
    UniteLourde(usint pointsVie, usint nbMunitions, usint nbProvisions,
                usint pointsBouclier);

    usint getPointsBouclier() const;

    void reparerBouclier();

    bool estLegere() const override;
    void sortieFlux(std::ostream &os) const override;
    void prendreDegats(usint degats) override;

private:
    usint _pointsBouclier;
    usint _MAX_POINTS_BOUCLIER;
};
