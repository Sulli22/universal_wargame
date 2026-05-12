#pragma once

#include "unite.hh"

class UniteLourde : virtual public Unite {
public:
    UniteLourde(Faction faction, stat pointsVie, stat nbMunitions,
                stat nbProvisions, stat pointsBouclier,
                Visibilite visibilite = Visibilite::totale);

    stat getPointsBouclier() const;     // les unités lourdes ont un bouclier en plus des PV
    stat getMaxPointsBouclier() const;

    void reparerBouclier();             // pas utilisée dans le jeu (pourrai etre associée à un effet de construction)
    bool estLegere() const override;
    void prendreDegats(stat degats) override;

// sortie flux
    void sortieFlux(std::ostream &os) const override;

private:
    stat _pointsBouclier;
    const stat _MAX_POINTS_BOUCLIER;
};
