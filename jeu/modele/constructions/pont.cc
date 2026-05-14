#include "pont.hh"

Pont::Pont()
{}

Stat Pont::getCoutImpl()
{
    return 10;
}

bool Pont::estPont() const
{
    return true;
}

void Pont::effectuerEffet(Unite *unite) const
{
    static_cast<void>(unite);
    // ne fait rien
}
