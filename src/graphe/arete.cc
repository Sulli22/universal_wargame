#include "arete.hh"

Arete::Arete(const Sommet &sommet1, const Sommet &sommet2) :
    _sommet1(sommet1), _sommet2(sommet2)
{}

Sommet Arete::getSommet1() const
{
    return _sommet1;
}

Sommet Arete::getSommet2() const
{
    return _sommet2;
}
