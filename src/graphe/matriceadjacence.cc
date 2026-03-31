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

    // Une idée : faire un dépliage par 2 comme il y a un décalage entre chaque lignes du plateau. Le voisin du haut et bas des lignes d'indices impaires se situe en [(i-1,j),(i-1,j+1), (i+1,j), (i+1, j+1)]
    // Pour les pairs c'est en [(i-1, j-1), (i-1, j), (i+1, j-1), (i+1, j)]. L'idée marche si on a que le meme nombre de lignes et colonnes et que pour les cases avec 6 voisins
    std::vector<bool> case00;
    case00.resize(nbLignes*nbColonnes);
    case00[1] = true;
    case00[nbColonnes] = true;
    _matrice.push_back(case00);

    // Pour avoir les voisins de chaques cases de la première ligne
    for (std::size_t j = 1; j<nbColonnes-1; j++) {
        std::vector<bool> ligne1;
        ligne1.resize(nbColonnes*nbLignes);
        ligne1[j-1] = true;
        ligne1[j+1] = true;
        ligne1[nbColonnes+j] = true;
        ligne1[nbColonnes+(j-1)] = true;
        _matrice.push_back(ligne1);
    }

    std::vector<bool> premiereLigneDerniereCase;
    premiereLigneDerniereCase.resize(nbColonnes*nbLignes);
    premiereLigneDerniereCase[nbColonnes-2] = true;
    premiereLigneDerniereCase[nbColonnes+(nbColonnes-2)] = true;
    premiereLigneDerniereCase[nbColonnes+(nbColonnes-1)] = true;
    _matrice.push_back(premiereLigneDerniereCase);

    std::size_t i = 1;
    for (; i < nbLignes-1; i += 2) {
        // Permet de mettre dans la matrice d'adjacence la ligne correspond à la premiere case de la ligne (tout à 0 pour le moment)

        std::vector<bool> premiereColonnePlateau1;
        premiereColonnePlateau1.resize(nbColonnes*nbLignes);
        premiereColonnePlateau1[(i-1)*nbColonnes] = true;
        premiereColonnePlateau1[(i-1)*nbColonnes+1] = true;
        premiereColonnePlateau1[i*nbColonnes+1] = true;
        premiereColonnePlateau1[(i+1)*nbColonnes+1] = true;
        premiereColonnePlateau1[(i+1)*nbColonnes] = true;
        _matrice.push_back(premiereColonnePlateau1);

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

        // Permet d'ajouter la derniere colonne de la ligne i
        std::vector<bool> derniereCaseLigneImpaire;
        derniereCaseLigneImpaire.resize(nbColonnes*nbLignes);
        derniereCaseLigneImpaire[(i-1)*nbColonnes+(nbColonnes-1)] = true;
        derniereCaseLigneImpaire[i*nbColonnes+(nbColonnes-2)] = true;
        derniereCaseLigneImpaire[(i+1)*nbColonnes+(nbColonnes-1)] = true;
        _matrice.push_back(derniereCaseLigneImpaire);

        // Ajoute la première case de la ligne i+1
        std::vector<bool> premiereCaseLignePaire;
        premiereCaseLignePaire.resize(nbColonnes * nbLignes);
        premiereCaseLignePaire[(i)*nbColonnes] = true;
        premiereCaseLignePaire[(i+1)*nbColonnes+1] = true;
        premiereCaseLignePaire[(i+2)*nbColonnes] = true;
        _matrice.push_back(premiereCaseLignePaire);

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

        // Ajout de la dernière case des lignes impaires
        std::vector<bool> derniereCaseLignePaire;
        derniereCaseLignePaire.resize(nbColonnes * nbLignes);
        derniereCaseLignePaire[i*nbColonnes+(nbColonnes-1)] = true;
        derniereCaseLignePaire[i*nbColonnes+(nbColonnes-2)] = true;
        derniereCaseLignePaire[(i+1)*nbColonnes+(nbColonnes-2)] = true;
        derniereCaseLignePaire[(i+2)*nbColonnes+(nbColonnes-2)] = true;
        derniereCaseLignePaire[(i+2)*nbColonnes+(nbColonnes)-1] = true;
        _matrice.push_back(derniereCaseLignePaire);
    }

    // Je fais pareil que pour la premiere ligne mais la c'est la derniere
    std::vector<bool> premiereCaseDerniereLigne;
    premiereCaseDerniereLigne.resize(nbColonnes * nbLignes);
    premiereCaseDerniereLigne[(nbLignes-2)*nbColonnes] = true;
    premiereCaseDerniereLigne[(nbLignes-2)*nbColonnes+1]=true;
    premiereCaseDerniereLigne[(nbLignes-1)*nbColonnes+1] = true;
    _matrice.push_back(premiereCaseDerniereLigne);

    // Ajout de la dernière ligne
    for (std::size_t j = 1; j < nbColonnes-1; j++){
        std::vector<bool> caseDerniereLigne;
        caseDerniereLigne.resize(nbColonnes*nbLignes);
        caseDerniereLigne[(nbLignes-1)*nbColonnes+(j-1)] = true;
        caseDerniereLigne[(nbLignes-2)*nbColonnes+j] = true;
        caseDerniereLigne[(nbLignes-2)*nbColonnes+(j+1)] = true;
        caseDerniereLigne[(nbLignes-1)*nbColonnes+(j+1)] = true;
        _matrice.push_back(caseDerniereLigne);
    }

    std::vector<bool> derniereCaseDerniereLigne;
    derniereCaseDerniereLigne.resize(nbColonnes * nbLignes);
    derniereCaseDerniereLigne[(nbLignes-1)*nbColonnes+(nbColonnes-2)] = true;
    derniereCaseDerniereLigne[(nbLignes-2)*nbColonnes+(nbColonnes-1)] = true;
    _matrice.push_back(derniereCaseDerniereLigne);
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
