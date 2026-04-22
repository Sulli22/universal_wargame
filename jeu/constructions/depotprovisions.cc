#include "depotprovisions.hh"

DepotProvisions::DepotProvisions():
    Construction(15)
{}

void DepotProvisions:: effectuerAction(Unite *unite) const
{
    unite->rechargerProvisions();
}
