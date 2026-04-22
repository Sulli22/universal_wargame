#pragma once

#include <ostream>

class Position {
public:
    Position(int q, int r);

    int getQ() const;
    int getR() const;

    Position operator+(const Position &pos) const;

// sortie flux
    void sortieFlux(std::ostream &os) const;

private:
    int _q; // coordonnee horizontale
    int _r; // coordonnee diagonale
};
