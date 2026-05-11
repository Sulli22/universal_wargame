#include "pont.hh"

Pont::Pont()
{}

stat Pont::getCoutImpl()
{
    return 10;
}

bool Pont::estPont() const
{
    return true;
}

void Pont::effectuerAction(Unite *unite) const
{
    static_cast<void>(unite);
    // ne fait rien
}
