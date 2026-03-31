#pragma once

#include <ostream>

class Position {
public:
    Position(int q, int r);
    //Position(const Position &pos);

    int getQ() const;
    int getR() const;

    //bool operator==(const Position &pos) const;
    Position operator+(const Position &pos) const;

    void sortieFlux(std::ostream &os) const;

private:
    int _q; // coordonnee horizontale
    int _r; // coordonnee diagonale
};
