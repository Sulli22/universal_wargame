#pragma once

#include <vector>
#include "sommet.hh"
#include "uniteterrestre.hh"

class SommetTerrestre : public Sommet {
public:
    SommetTerrestre();

private:
    std::vector<UniteTerrestre> _uniteBasse;
};

