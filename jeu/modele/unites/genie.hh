#pragma once

#include <infanterie.hh>
#include "caseterrestre.hh"

class Genie : public Infanterie {
public:
    Genie(Faction faction,
          Stat pointsVie = _POINTS_VIE_INIT/2,
          Stat nbMunitions = _NB_MUNITIONS_INIT/2,
          Stat nbProvisions = _NB_PROVISIONS_INIT*3);

    std::string getNom() const override;
    std::vector<IndiceAction> getIndicesActionsPossibles() const override;

    void rechargerProvisions() override;
    bool peutDepenser(Stat cout) const;
    void construire(CaseTerrestre *caseOuConstruire,
                    std::unique_ptr<Construction> construction);
};

