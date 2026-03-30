#include "graphe.hh"
#include "infanterie.hh"
#include "sousmarin.hh"
#include <iostream>

int main()
{
    // test graphe
    MatriceAdjacence m(5);
    Graphe g(m);
    g.sortieFlux(std::cout); std::cout << std::endl;
    std::cout<<"Voisins de 0 : ";
    g.voisins(g.getSommets()[0]); std::cout << std::endl;

    // test infanterie
    Infanterie I;
    I.sortieFlux(std::cout); std::cout << std::endl;

    // test sous-marin
    SousMarin SM;
    SM.sortieFlux(std::cout); std::cout << std::endl;

    return 0;
}
