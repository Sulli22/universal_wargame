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

// sommets entournés :[(i-1, j-1), (i-1, j), (i, j+1), (i+1, j+1), (i+1, j), (i, j-1)]
// sommets sur les bords gauches indices impairs : [(i-1, j), (i-1, j+1), (i, j+1),  (i+1, j+1), (i+1, j)]
// sommets sur les bords gauches indices pairs : [(i-1, j), (i, j+1), (i+1, j)]
// sommets sur les bords droits indices impairs : [(i-1, j+1), (i-1, j), (i, j-1), (i+1, j), (i+1, j+1)]
// sommets sur les bords droits indices pairs : [
