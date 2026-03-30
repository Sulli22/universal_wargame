#include "graphe.hh"
#include "infanterie.hh"
#include <iostream>

int main()
{
    // test graphe
    MatriceAdjacence m(5);
    Graphe g(m);
    g.sortieFlux(std::cout); std::cout << std::endl;
    std::cout<<"Voisins de 0 : ";
    g.voisins(g.getSommets()[0]);
    // test infanterie
    Infanterie I(50, 16, 10);
    I.sortieFlux(std::cout); std::cout << std::endl;

    return 0;
}
