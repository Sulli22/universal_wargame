#include "depotmunitions.hh"

DepotMunitions::DepotMunitions()
{}

stat DepotMunitions::getCoutImpl()
{
    return 10;
}

void DepotMunitions:: effectuerAction(Unite *unite) const
{
    unite->rechargerMunitions();
}
