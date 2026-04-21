#pragma once

#include <infanterie.hh>
#include "caseterrestre.hh"

class Genie : public Infanterie {
public:
    Genie(Faction faction,
          usint pointsVie = _POINTS_VIE_INIT/2,
          usint nbMunitions = _NB_MUNITIONS_INIT/2,
          usint nbProvisions = _NB_PROVISIONS_INIT*2);

    std::string getNom() const override;
    usint getNbActionsPossibles() const override;

    void construire(CaseTerrestre *caseOuConstruire, std::unique_ptr<Construction> construction) const;
};

