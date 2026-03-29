#pragma once

#include <vector>
#include <ostream>

class MatriceAdjacence {
public:
    MatriceAdjacence(std::size_t taille);

    std::vector<std::vector<bool>> getMatrice() const;
    void sortieFlux(std::ostream &os) const;

private:
    std::vector<std::vector<bool>> _matrice;
    std::size_t _taille;
};

