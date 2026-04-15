#include "depotprovisions.hh"

DepotProvisions::DepotProvisions():
    Construction(40)
{}

void DepotProvisions:: effectuerAction(Unite *unite) const
{
    unite->rechargerProvisions();
}
