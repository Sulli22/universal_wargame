#include "depotprovisions.hh"

DepotProvisions::DepotProvisions()
{}

stat DepotProvisions::getCoutImpl()
{
    return 15;
}

void DepotProvisions:: effectuerEffet(Unite *unite) const
{
    unite->rechargerProvisions();
}
