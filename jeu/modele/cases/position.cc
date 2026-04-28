#include "position.hh"

Position::Position(int q, int r):
    _q(q), _r(r)
{}

int Position::getQ() const
{
    return _q;
}

int Position::getR() const
{
    return _r;
}

Position Position::operator+(const Position &pos) const
{
    return Position(_q + pos._q, _r + pos._r);
}

void Position::sortieFlux(std::ostream &os) const
{
    os << "(" << _q << "," << _r << ")";
}
