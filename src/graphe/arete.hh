#pragma once
#include "sommet.hh"

class Arete
{
public:
    Arete(const Sommet & sommet1,const Sommet & sommet2);
    Sommet getSommet1() const;
    Sommet getSommet2() const;

private:
    Sommet _sommet1;
    Sommet _sommet2;
};

