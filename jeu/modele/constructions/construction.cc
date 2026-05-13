#include "construction.hh"

#include "depotmunitions.hh"
#include "depotprovisions.hh"
#include "infirmerie.hh"
#include "pont.hh"

template<typename Derivee>
ConstructionTemplate<Derivee>::ConstructionTemplate()
{}

Construction::Construction()
{}

void Construction::effectuerEffet(std::vector<Unite *> unites) const
{
    for (Unite *unite : unites)
        effectuerEffet(unite);
}

bool Construction::estPont() const
{
    return false;
}

template class ConstructionTemplate<DepotMunitions>;
template class ConstructionTemplate<DepotProvisions>;
template class ConstructionTemplate<Infirmerie>;
template class ConstructionTemplate<Pont>;
