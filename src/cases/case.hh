#pragma once

#include "position.hh"

class Case {
public:
    Case(const Position &pos);

    const Position &getPos() const;

private:
    Position _pos;
};
