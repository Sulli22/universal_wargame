#pragma once

#include <vector>
#include <ostream>
#include <map>
#include "case.hh"

class Carte {
public:
    Carte(std::string nomFichier);

    std::size_t getLargeur() const;
    std::size_t getHauteur() const;
    const std::vector<std::vector<std::unique_ptr<Case>>> &getContenu() const;

    Case *accesCase(const Position &pos);
    bool positionValide(const Position &pos) const;
    std::vector<Case *> getVoisines(const Case &c) const;
    std::map<Case *, int> getCasesAtteignables(Case *depart, Unite *unite) const;

    void soriteFlux(std::ostream &os) const;

    void afficherDetails(std::ostream &os);

private:
    std::size_t _largeur;
    std::size_t _hauteur;
    std::vector<std::vector<std::unique_ptr<Case>>> _contenu;

    static const std::vector<Position> _DIRECTIONS;
};
