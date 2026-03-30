#include "matriceadjacence.hh"
#include <stdlib.h>
#include <time.h>
#include <iostream>

MatriceAdjacence::MatriceAdjacence(unsigned int nbLignes,unsigned int nbColonnes)
{
    /*
    srand(time(NULL));
    for (std::size_t i = 0; i < taille; i++) {
        std::vector<bool> ligne;

        // Ceci permet de ne pas remplir inutilement le reste de la matrice
        for (std::size_t j = 0; j < i; j++) {
            ligne.push_back(_matrice[j][i]);
        }
        ligne.push_back(0);

        for (std::size_t j = i+1; j < taille; j++)
            ligne.push_back(rand()%2);
        _matrice.push_back(ligne);
    }
    */
   // Pour la premiere ligne du plateau pour le moment la matrice d'adjacence mets tout les sommets à non voisins
    for (std::size_t j = 0; j < nbColonnes; j++) {
        std::vector<bool> ligne;
        ligne.resize(nbColonnes*nbLignes);
        //std::cout<<ligne1.size()<<" ";
        _matrice.push_back(ligne);
    }
    // Une idée : faire un dépliage par 2 comme il y a un décalage entre chaque lignes du plateau. Le voisin du haut et bas des lignes d'indices impaires se situe en [(i-1,j),(i-1,j+1), (i+1,j), (i+1, j+1)]
    // Pour les pairs c'est en [(i-1, j-1), (i-1, j), (i+1, j-1), (i+1, j)]. L'idée marche si on a que le meme nombre de lignes et colonnes et que pour les cases avec 6 voisins
    for (std::size_t i = 1; i < nbLignes-1; i++) {
        // Permet de mettre dans la matrice d'adjacence la ligne correspond à la premiere case de la ligne (tout à 0 pour le moment)
        std::vector<bool> colonne1Plateau;
        colonne1Plateau.resize(nbColonnes*nbLignes);
        _matrice.push_back(colonne1Plateau);

        for (std::size_t j = 1; j < nbColonnes-1; j++) {
            //std::cout<<_matrice.size()<<" ";
            int k = i*nbColonnes+j;
            std::vector<bool> ligneMatrice;
            ligneMatrice.resize(nbLignes*nbColonnes);
            ligneMatrice[(i-1)*nbColonnes+j] = true;
            ligneMatrice[(i-1)*nbColonnes+(j+1)] = true;
            ligneMatrice[i*nbColonnes+(j+1)] = true;
            ligneMatrice[(i+1)*nbColonnes+(j+1)] = true;
            ligneMatrice[(i+1)*nbColonnes+j] = true;
            ligneMatrice[i*nbColonnes+(j-1)] = true;

            _matrice.push_back(ligneMatrice);
        }

        // Permet de mettre dans la matrice d'adjacence la ligne correspond à la dernière case de la ligne (tout à 0 pour le moment)
        std::vector<bool> derniereColonnePlateau;
        derniereColonnePlateau.resize(nbColonnes*nbLignes);
        //std::cout<<ligne1.size()<<" ";
        _matrice.push_back(derniereColonnePlateau);

    }

    // Je fais pareil que pour la premiere ligne mais la c'est la derniere
    for (std::size_t j = 0; j < nbColonnes; j++) {
        std::vector<bool> ligne;
        ligne.resize(nbColonnes*nbLignes);
        //std::cout<<ligne1.size()<<" ";
        _matrice.push_back(ligne);
    }
}

std::vector<std::vector<bool>> MatriceAdjacence::getMatrice() const
{
    return _matrice;
}

void MatriceAdjacence::sortieFlux(std::ostream &os) const
{
    for (std::size_t i = 0; i < _matrice.size(); i++) {

        for (std::size_t k = 0; k < _matrice.size(); k++)
            os << _matrice[i][k] << " ";
        os << std::endl;
    }
}
