#include "matriceadjacence.hh"
#include <stdlib.h>
#include <time.h>
#include <iostream>

MatriceAdjacence::MatriceAdjacence(std::size_t taille) :
    _taille(taille)
{
    srand(time(NULL));
    for (std::size_t i = 0; i < taille; i++) {
        std::vector<bool> ligne;
        ligne.push_back(0);

        // Ceci permet de ne pas remplir inutilement le reste de la matrice
        for (std::size_t j = 0; j < taille-i; j++)
            ligne.push_back(rand()%2);
        _matrice.push_back(ligne);
    }
}

std::vector<std::vector<bool>> MatriceAdjacence::getMatrice() const
{
    return _matrice;
}

void MatriceAdjacence::sortieFlux(std::ostream &os) const
{
    for (std::size_t i = 0; i < _taille; i++) {
        for (std::size_t j = 0; j < i; j++)
            os << "  "; // Permet d'avoir les colonnes au bon endroit

        for (std::size_t k = 0; k < _taille-i; k++)
            os << _matrice[i][k] << " ";
        os << std::endl;
    }
}
