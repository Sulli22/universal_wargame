#include "depotprovisions.hh"

DepotProvisions::DepotProvisions()
{}

Stat DepotProvisions::getCoutImpl()
{
    return 15;
}

void DepotProvisions:: effectuerEffet(Unite *unite) const
{
    unite->rechargerProvisions();
}
