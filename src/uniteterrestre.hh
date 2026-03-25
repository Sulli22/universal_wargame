#pragma once
#include "unite.hh"


class UniteTerrestre: public Unite {
public:
    UniteTerrestre(unsigned int pointsVie, unsigned int nbMunitions);

    virtual unsigned int getTaille() const=0;
};
