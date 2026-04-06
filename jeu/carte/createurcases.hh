#pragma once

#include "case.hh"
#include "position.hh"

class CreateurCases {
public:
    static std::unique_ptr<Case> creer(char c, const Position &pos);
};
