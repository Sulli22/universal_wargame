#pragma once
#include "unite.hh"


class UniteTerrestre: public Unite {
public:
    UniteTerrestre(int pointsVie, int pointsAttaque, int capaciteDeDeplacement, unsigned int taille);
    unsigned int getTaille() const;
private:
    unsigned int _taille;
};
