#pragma once

#include <infanterie.hh>
#include "caseterrestre.hh"

class Genie : public Infanterie {
public:
    Genie(Faction faction,
          stat pointsVie = _POINTS_VIE_INIT/2,
          stat nbMunitions = _NB_MUNITIONS_INIT/2,
          stat nbProvisions = _NB_PROVISIONS_INIT*2);

    std::string getNom() const override;
    std::set<indiceAction> getIndicesActionsPossibles() const override;

    void construire(CaseTerrestre *caseOuConstruire,
                    std::unique_ptr<Construction> construction);
};

