#include "depotmunitions.hh"

DepotMunitions::DepotMunitions()
{}

stat DepotMunitions::getCoutImpl()
{
    return 10;
}

void DepotMunitions:: effectuerEffet(Unite *unite) const
{
    unite->rechargerMunitions();
}
