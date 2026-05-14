#pragma once

#include "unite.hh"

class UniteLourde : virtual public Unite {
public:
    UniteLourde(Faction faction, Stat pointsVie, Stat nbMunitions,
                Stat nbProvisions, Stat pointsBouclier, Visibilite visibilite);

    Stat getPointsBouclier() const;     // les unités lourdes ont un bouclier en plus des PV
    Stat getMaxPointsBouclier() const;

    void reparerBouclier();             // pas utilisée dans le jeu (pourrai etre associée à un effet de construction)
    bool estLegere() const override;
    void prendreDegats(Stat degats) override;

// sortie flux
    void sortieFlux(std::ostream &os) const override;

private:
    Stat _pointsBouclier;
    const Stat _MAX_POINTS_BOUCLIER;
};
