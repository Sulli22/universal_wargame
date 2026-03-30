#pragma once
#include "sommet.hh"
#include "matriceadjacence.hh"

class Graphe {
public:
    Graphe(const MatriceAdjacence & matriceAdj);
    std::vector<std::pair<std::shared_ptr<Sommet>, std::shared_ptr<Sommet>>> getAretes() const;
    std::vector<std::shared_ptr<Sommet>> getSommets() const;

    std::vector<std::shared_ptr<Sommet>> voisins(std::shared_ptr<Sommet> sommet) const;

    void sortieFlux(std::ostream &os) const;

private:
    std::vector<std::shared_ptr<Sommet>> _sommets;
    MatriceAdjacence _matriceAdj;
};

