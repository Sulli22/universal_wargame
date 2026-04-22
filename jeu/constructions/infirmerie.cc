#include "infirmerie.hh"

Infirmerie::Infirmerie():
    Construction(10)
{}

void Infirmerie:: effectuerAction(Unite *unite) const
{
    unite->regagnerViePartielle();
}
