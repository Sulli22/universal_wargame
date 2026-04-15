#include "infirmerie.hh"

Infirmerie::Infirmerie():
    Construction(30)
{}

void Infirmerie:: effectuerAction(Unite *unite) const
{
    unite->regagnerViePartielle();
}
