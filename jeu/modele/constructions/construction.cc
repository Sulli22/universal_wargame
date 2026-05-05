#include "construction.hh"

Construction::Construction(uint16_t cout):
    _cout(cout)
{}

uint16_t Construction::getCout() const
{
    return _cout;
}

void Construction::effectuerAction(std::vector<Unite *> unites) const
{
    for (Unite *unite : unites)
        effectuerAction(unite);
}

bool Construction::estPont() const
{
    return false;
}
