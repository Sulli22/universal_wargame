#pragma once

#include "unite.hh"

class UniteLegere : virtual public Unite {
public:
    UniteLegere(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                uint16_t nbProvisions, Visibilite visibilite = Visibilite::totale);

    virtual uint16_t getTaille() const =0;

    bool estLegere() const override;

// sortie flux
    void sortieFlux(std::ostream &os) const override;
};
