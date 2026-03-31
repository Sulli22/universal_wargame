#pragma once

#include <vector>
#include <ostream>
#include "case.hh"

class Carte {
public:
    Carte(std::size_t largeur, std::size_t hateur);

    std::size_t getLargeur() const;
    std::size_t getHauteur() const;
    const std::vector<std::vector<Case>> &getContenu() const;

    Case *accesCase(const Position &pos);
    bool positionValide(const Position &pos) const;
    std::vector<Case> getVoisins(const Case &c) const;

    void soriteFlux(std::ostream &os) const;

private:
    std::size_t _largeur;
    std::size_t _hauteur;
    std::vector<std::vector<Case>> _contenu;

    static const std::vector<Position> _DIRECTIONS;
};
