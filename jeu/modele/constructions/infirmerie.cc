#include "infirmerie.hh"

Infirmerie::Infirmerie()
{}

stat Infirmerie::getCoutImpl()
{
    return 10;
}

void Infirmerie:: effectuerEffet(Unite *unite) const
{
    unite->regagnerVie();
}
