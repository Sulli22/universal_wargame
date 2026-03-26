#include "matriceadjacence.hh"
#include <stdlib.h>
#include <time.h>
#include <iostream>

MatriceAdjacence::MatriceAdjacence(std::size_t taille):_taille(taille)
{
    srand(time(NULL));
    for (unsigned int i=0; i<taille; i++){
        std::vector<bool> matriceAux;
        matriceAux.push_back(0);
        // Ceci permet de ne pas remplir inutilement le reste de la matrice
        for (unsigned int j=0; j<taille-i; j++){
            matriceAux.push_back(rand()%2);
        }
        _matrice.push_back(matriceAux);
    }


}

std::vector<std::vector<bool>> MatriceAdjacence::getMatrice() const {
    return _matrice;
}

void MatriceAdjacence::afficher() const {
    for (unsigned int i=0; i<_taille; i++){
        for (unsigned int j=0; j<i; j++) std::cout<<"  "; // Permet d'avoir les colonnes au bon endroit

        for (unsigned int k=0; k<_taille-i; k++){
            std::cout<<_matrice[i][k]<<" ";
        }
        std::cout<<std::endl;
    }
}
