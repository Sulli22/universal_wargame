#include "uniteterrestre.hh"

UniteTerrestre::UniteTerrestre(int pointsVie, int pointsAttaque, int capaciteDeDeplacement, unsigned int taille) :
    Unite(pointsVie, pointsAttaque, capaciteDeDeplacement),
    _taille(taille) {}

unsigned int UniteTerrestre::getTaille() const {
    return _taille;
}
