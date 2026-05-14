#include "depotmunitions.hh"

DepotMunitions::DepotMunitions()
{}

Stat DepotMunitions::getCoutImpl()
{
    return 10;
}

void DepotMunitions:: effectuerEffet(Unite *unite) const
{
    unite->rechargerMunitions();
}
