#include "graphe.hh"
#include <iostream>

Graphe::Graphe(const MatriceAdjacence & matriceAdj):
    _matriceAdj(matriceAdj)
{}

std::vector<std::pair<int, int>> Graphe::getAretes() const
{
    auto matrice = _matriceAdj.getMatrice();
    std::vector<std::pair<int, int>> aretes;

    for (std::size_t i = 0; i < matrice.size(); i++) {
        for (std::size_t j = i; j < matrice.size(); j++) {
            if (matrice[i][j])
                // Le i+j permet d'avoir le bon sommet
                aretes.push_back(std::make_pair(i, j));
        }
    }
    return aretes;
}

std::vector<int> Graphe::getSommets() const
{
    std::vector<int> sommets;
    for (std::size_t i = 0; i < _matriceAdj.getMatrice().size(); i++)
        sommets.push_back(i);
    return sommets;
}

void Graphe::sortieFlux(std::ostream &os) const
{
    _matriceAdj.sortieFlux(os);

    // affichage sommets
    auto sommets = getSommets();
    std::string strSommets = "{ ";
    for (std::size_t i = 0; i < sommets.size()-1; i++)
        strSommets += std::to_string(sommets[i]) + ", ";
    strSommets += std::to_string(sommets[sommets.size()-1]) + " }";

    os << "V = " << strSommets << std::endl;

    // affichage arêtes
    auto aretes = getAretes();
    std::string strAretes = "{ ";
    for (std::size_t i = 0; i < aretes.size()-1; i++) {
        auto p = aretes[i];
        strAretes += "(" + std::to_string(p.first) +
                     ", " +std::to_string(p.second) + ") ";
    }

    auto p = aretes[aretes.size()-1];
    strAretes += "(" + std::to_string(p.first) +
                 ", " + std::to_string(p.second) + ") }";

    os << "E = " << strAretes;
}
