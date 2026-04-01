#pragma once

#include <uniteaerienne.hh>

class Bombardier : public UniteAerienne
{
public:
    Bombardier(usint pointsVie, usint nbMunitions, usint nbProvisions,
               usint pointsBouclier);
};

