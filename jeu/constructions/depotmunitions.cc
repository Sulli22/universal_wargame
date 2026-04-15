#include "depotmunitions.hh"

DepotMunitions::DepotMunitions():
    Construction(30)
{}

void DepotMunitions:: effectuerAction(Unite *unite) const
{
    unite->rechargerMunitions();
}
