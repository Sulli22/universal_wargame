#pragma once

#include <infanterie.hh>
#include "caseterrestre.hh"

class Genie : public Infanterie {
public:
    Genie(Faction faction,
          uint16_t pointsVie = _POINTS_VIE_INIT/2,
          uint16_t nbMunitions = _NB_MUNITIONS_INIT/2,
          uint16_t nbProvisions = _NB_PROVISIONS_INIT*2);

    std::string getNom() const override;
    uint16_t getNbActionsPossibles() const override;

    void construire(CaseTerrestre *caseOuConstruire,
                    std::unique_ptr<Construction> construction);
};

