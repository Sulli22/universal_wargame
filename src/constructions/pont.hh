#pragma once

#include "construction.hh"

class Pont : public Construction
{
public:
    Pont();
    bool estPont() const override;
};

