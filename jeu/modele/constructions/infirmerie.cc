#include "infirmerie.hh"

Infirmerie::Infirmerie()
{}

stat Infirmerie::getCoutImpl()
{
    return 10;
}

void Infirmerie:: effectuerAction(Unite *unite) const
{
    unite->regagnerViePartielle();
}
