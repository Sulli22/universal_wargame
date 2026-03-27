#pragma once

#include <vector>

class MatriceAdjacence {
public:
    MatriceAdjacence(std::size_t taille);

    std::vector<std::vector<bool>> getMatrice() const;
    void afficher() const;

private:
    std::vector<std::vector<bool>> _matrice;
    std::size_t _taille;
};

