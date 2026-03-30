#include "graphe.hh"
#include <iostream>

Graphe::Graphe(const MatriceAdjacence & matriceAdj):
    _matriceAdj(matriceAdj)
{
    std::shared_ptr<Sommet> sommet1(new Sommet());
    std::shared_ptr<Sommet> sommet2(new Sommet());
    std::shared_ptr<Sommet> sommet3(new Sommet());
    std::shared_ptr<Sommet> sommet4(new Sommet());
    std::shared_ptr<Sommet> sommet5(new Sommet());

    _sommets.push_back(sommet1);
    _sommets.push_back(sommet2);
    _sommets.push_back(sommet3);
    _sommets.push_back(sommet4);
    _sommets.push_back(sommet5);
}

std::vector<std::pair<std::shared_ptr<Sommet>, std::shared_ptr<Sommet>>> Graphe::getAretes() const
{
    auto matrice = _matriceAdj.getMatrice();
    std::vector<std::pair<std::shared_ptr<Sommet>, std::shared_ptr<Sommet>>> aretes;

    for (std::size_t i = 0; i < matrice.size(); i++) {
        for (std::size_t j = i; j < matrice.size(); j++) {
            if (matrice[i][j])
                aretes.push_back(std::make_pair(_sommets[i], _sommets[j]));
        }
    }
    return aretes;
}

std::vector<std::shared_ptr<Sommet>> Graphe::getSommets() const
{
    return _sommets;
}

std::vector<std::shared_ptr<Sommet>> Graphe::voisins(std::shared_ptr<Sommet> sommet) const {
    std::vector<std::vector<bool>> matrice(_matriceAdj.getMatrice());
    std::vector<std::shared_ptr<Sommet>> voisinsSommet;

    const unsigned int id(sommet->getId());
    for (std::size_t j = 0; j < matrice.size(); j++) {

        if (matrice[id][j]) {
            voisinsSommet.push_back(_sommets[j]);
            //std::cout<<_sommets[j]->getId()<<" ";
        }
    }
    //std::cout<<std::endl;

    return voisinsSommet;
}

void Graphe::sortieFlux(std::ostream &os) const
{
    _matriceAdj.sortieFlux(os);

    // affichage sommets
    auto sommets = getSommets();
    std::string strSommets = "{ ";
    for (std::size_t i = 0; i < sommets.size()-1; i++)
        strSommets += std::to_string(sommets[i]->getId()) + ", ";
    strSommets += std::to_string(sommets[sommets.size()-1]->getId()) + " }";

    os << "V = " << strSommets << std::endl;

    // affichage arêtes
    auto aretes = getAretes();
    std::string strAretes = "{ ";
    for (std::size_t i = 0; i < aretes.size()-1; i++) {
        auto p = aretes[i];
        strAretes += "(" + std::to_string(p.first->getId()) +
                     ", " +std::to_string(p.second->getId()) + ") ";
    }

    auto p = aretes[aretes.size()-1];
    strAretes += "(" + std::to_string(p.first->getId()) +
                 ", " + std::to_string(p.second->getId()) + ") }";

    os << "E = " << strAretes;
}
