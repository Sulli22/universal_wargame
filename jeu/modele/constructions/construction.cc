#include "construction.hh"

Construction::Construction(stat cout):
    _cout(cout)
{}

stat Construction::getCout() const
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
