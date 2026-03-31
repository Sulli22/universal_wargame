#include "case.hh"

Case::Case(const Position &pos):
    _pos(pos)
{}

const Position &Case::getPos() const
{
    return _pos;
}
