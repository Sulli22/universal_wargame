#include "depotprovisions.hh"

DepotProvisions::DepotProvisions()
{}

stat DepotProvisions::getCoutImpl()
{
    return 15;
}

void DepotProvisions:: effectuerAction(Unite *unite) const
{
    unite->rechargerProvisions();
}
