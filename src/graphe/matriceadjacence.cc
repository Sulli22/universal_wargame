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
        _matrice.push_back(ligne);
    }
    // Une idée : faire un dépliage par 2 comme il y a un décalage entre chaque lignes du plateau. Le voisin du haut et bas des lignes d'indices impaires se situe en [(i-1,j),(i-1,j+1), (i+1,j), (i+1, j+1)]
    // Pour les pairs c'est en [(i-1, j-1), (i-1, j), (i+1, j-1), (i+1, j)]. L'idée marche si on a que le meme nombre de lignes et colonnes et que pour les cases avec 6 voisins
    std::vector<bool> case00;

    std::size_t i = 1;
    for (; i < nbLignes-1; i += 2) {
        // Permet de mettre dans la matrice d'adjacence la ligne correspond à la premiere case de la ligne (tout à 0 pour le moment)
        std::vector<bool> colonne1Plateau1;
        colonne1Plateau1.resize(nbColonnes*nbLignes);
        _matrice.push_back(colonne1Plateau1);

        for (std::size_t j = 1 ; j < nbColonnes-1; j++) {
            //std::cout<<_matrice.size()<<" ";

            std::vector<bool> ligneMatrice1;
            ligneMatrice1.resize(nbLignes*nbColonnes);
            ligneMatrice1[(i-1)*nbColonnes+j] = true;
            ligneMatrice1[(i-1)*nbColonnes+(j+1)] = true;
            ligneMatrice1[i*nbColonnes+(j+1)] = true;
            ligneMatrice1[(i+1)*nbColonnes+(j+1)] = true;
            ligneMatrice1[(i+1)*nbColonnes+j] = true;
            ligneMatrice1[i*nbColonnes+(j-1)] = true;
            _matrice.push_back(ligneMatrice1);

        }

        // Permet d'ajouter la derniere colonne de la ligne i et la premiere de la ligne i+1 (tout false pour le moment)
        std::vector<bool> derniereColonnePlateau1;
        derniereColonnePlateau1.resize(nbColonnes*nbLignes);
        _matrice.push_back(derniereColonnePlateau1);
        _matrice.push_back(derniereColonnePlateau1);

        // Boucle pour la ligne i+1
        for (std::size_t j=1; j<nbColonnes-1; j++) {

            std::vector<bool> ligneMatrice2;
            ligneMatrice2.resize(nbLignes*nbColonnes);
            ligneMatrice2[i*nbColonnes+(j-1)] = true;
            ligneMatrice2[i*nbColonnes+j] = true;
            ligneMatrice2[(i+1)*nbColonnes+(j+1)] = true;
            ligneMatrice2[(i+1)*nbColonnes+(j-1)] = true;
            ligneMatrice2[(i+2)*nbColonnes+(j-1)] = true;
            ligneMatrice2[(i+2)*nbColonnes+(j)] = true;
            _matrice.push_back(ligneMatrice2);
        }

        // Permet de mettre dans la matrice d'adjacence la ligne correspond à la dernière case de la ligne (tout à 0 pour le moment)
        std::vector<bool> derniereColonnePlateau2;
        derniereColonnePlateau2.resize(nbColonnes*nbLignes);
        //std::cout<<ligne1.size()<<" ";
        _matrice.push_back(derniereColonnePlateau2);

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
