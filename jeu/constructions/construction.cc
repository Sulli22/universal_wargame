#include "construction.hh"

Construction::Construction(usint cout):
    _cout(cout)
{}

usint Construction::getCout() const
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
