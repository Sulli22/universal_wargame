#include "construction.hh"

Construction::Construction(usint cout):
    _cout(cout)
{}

usint Construction::getCout() const
{
    return _cout;
}

bool Construction::estPont() const
{
    return false;
}
