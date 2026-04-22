#include "depotmunitions.hh"

DepotMunitions::DepotMunitions():
    Construction(10)
{}

void DepotMunitions:: effectuerAction(Unite *unite) const
{
    unite->rechargerMunitions();
}
