#pragma once

#include "unite.hh"

class UniteLourde : virtual public Unite {
public:
    UniteLourde(Faction faction, uint16_t pointsVie, uint16_t nbMunitions,
                uint16_t nbProvisions, uint16_t pointsBouclier,
                Visibilite visibilite = Visibilite::totale);

    uint16_t getPointsBouclier() const;
    uint16_t getMaxPointsBouclier() const;

    void reparerBouclier();
    bool estLegere() const override;
    void prendreDegats(uint16_t degats) override;

// sortie flux
    void sortieFlux(std::ostream &os) const override;

private:
    uint16_t _pointsBouclier;
    uint16_t const _MAX_POINTS_BOUCLIER;
};
