#pragma once

#include <infanterie.hh>
#include "caseterrestre.hh"

class Genie : public Infanterie {
public:
    Genie(Faction faction,
          stat pointsVie = _POINTS_VIE_INIT/2,
          stat nbMunitions = _NB_MUNITIONS_INIT/2,
          stat nbProvisions = _NB_PROVISIONS_INIT*3);

    std::string getNom() const override;
    std::vector<indiceAction> getIndicesActionsPossibles() const override;

    void rechargerProvisions() override;
    bool peutDepenser(stat cout) const;
    void construire(CaseTerrestre *caseOuConstruire,
                    std::unique_ptr<Construction> construction);
};

