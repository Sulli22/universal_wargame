#pragma once

#include <vector>
#include <ostream>
#include "case.hh"

class Carte {
public:
    Carte(std::size_t largeur, std::size_t hateur);

    void soriteFlux(std::ostream &os) const;

private:
    std::size_t _largeur;
    std::size_t _hauteur;
    std::vector<std::vector<Case>> _contenu;
};
