#pragma once
#include "carte.hh"

class Jeu {
public:
    Jeu(const std::string &nomGuerre);

private:
    Carte _plateau;
};

