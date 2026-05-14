#include "infirmerie.hh"

Infirmerie::Infirmerie()
{}

Stat Infirmerie::getCoutImpl()
{
    return 10;
}

void Infirmerie:: effectuerEffet(Unite *unite) const
{
    unite->regagnerVie();
}
