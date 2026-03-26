#pragma once
#include "matriceadjacence.hh"


class Graphe
{
public:
    Graphe(const MatriceAdjacence & matriceAdj);
    std::vector<std::pair<int, int>> getAretes() const;
    std::vector<int> getSommets() const;

    void afficher() const;

private:
    MatriceAdjacence _matriceAdj;
};

