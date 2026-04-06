#pragma once

#include <vector>
#include <ostream>

class MatriceAdjacence {
public:
    MatriceAdjacence(unsigned int nbLignes, unsigned int nbColonnes);

    std::vector<std::vector<bool>> getMatrice() const;
    void sortieFlux(std::ostream &os) const;

private:
    std::vector<std::vector<bool>> _matrice;
};

