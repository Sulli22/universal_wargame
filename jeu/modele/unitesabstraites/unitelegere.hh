#pragma once

#include "unite.hh"

class UniteLegere : virtual public Unite {
public:
    UniteLegere(Faction faction, stat pointsVie, stat nbMunitions,
                stat nbProvisions, Visibilite visibilite = Visibilite::totale);

    virtual stat getTaille() const =0;

    bool estLegere() const override;

// sortie flux
    void sortieFlux(std::ostream &os) const override;
};
