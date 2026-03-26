#include "graphe.hh"
#include <iostream>

Graphe::Graphe(const MatriceAdjacence & matriceAdj):_matriceAdj(matriceAdj)
{

}

std::vector<std::pair<int,int>> Graphe::getAretes() const{

    std::vector<std::vector<bool>> matrice = _matriceAdj.getMatrice();
    std::vector<std::pair<int,int>> aretes;

    for (std::size_t i=0; i<matrice.size(); i++){
        for (std::size_t j=0; j<matrice.size()-i; j++){
            if (matrice[i][j]){
                // Le i+j permet d'avoir le bon sommet
                aretes.push_back(std::make_pair(i,j+i));
            }
        }
    }
    return aretes;
}

std::vector<int> Graphe::getSommets() const {
    std::vector<int> sommets;
    for (std::size_t i=0; i<_matriceAdj.getMatrice().size(); i++){
        sommets.push_back(i);
    }
    return sommets;
}


void Graphe::afficher() const{
    _matriceAdj.afficher();
    std::string stringAretes = "{";
    std::vector<std::pair<int,int>> aretes = getAretes();
    for (std::size_t i=0; i<aretes.size(); i++){
        std::pair<int,int> p = aretes[i];
        stringAretes += "("+std::to_string(p.first)+","+std::to_string(p.second) + ")";
        if (i == aretes.size()-1) stringAretes += "}";
        stringAretes += ",";
    }


    std::vector<int> sommets = getSommets();
    std::string stringSommets = "{";
    for (std::size_t i=0; i<sommets.size(); i++){
        stringSommets += std::to_string(i);
        if (i == sommets.size()-1) stringSommets += "}";
        else stringSommets += ", ";
    }

    std::cout<<"V = "<<stringSommets<<std::endl;
    std::cout<<"E = "<<stringAretes<<std::endl;


}
