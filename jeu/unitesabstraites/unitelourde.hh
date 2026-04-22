#pragma once

#include "unite.hh"

class UniteLourde : virtual public Unite {
public:
    UniteLourde(Faction faction, usint pointsVie, usint nbMunitions,
                usint nbProvisions, usint pointsBouclier,
                Visibilite visibilite = Visibilite::totale);

    usint getPointsBouclier() const;

    void reparerBouclier();
    bool estLegere() const override;
    void prendreDegats(usint degats) override;

// sortie flux
    void sortieFlux(std::ostream &os) const override;

private:
    usint _pointsBouclier;
    usint const _MAX_POINTS_BOUCLIER;
};
