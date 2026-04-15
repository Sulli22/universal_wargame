#include "pont.hh"

Pont::Pont():
    Construction(10)
{}

bool Pont::estPont() const
{
    return true;
}

void Pont::effectuerAction(Unite *unite) const
{
    // ne fait rien
}
