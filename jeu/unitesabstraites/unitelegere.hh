#pragma once

#include "unite.hh"

class UniteLegere : virtual public Unite {
public:
    UniteLegere(Faction faction, usint pointsVie, usint nbMunitions,
                usint nbProvisions, Visibilite visibilite = Visibilite::totale);

    virtual usint getTaille() const =0;

    bool estLegere() const override;
    void sortieFlux(std::ostream &os) const override;
};
