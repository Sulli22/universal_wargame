#include "graphe.hh"
#include "infanterie.hh"
#include <iostream>

int main()
{
    // test graphe
    MatriceAdjacence m(5);
    Graphe g(m);
    g.sortieFlux(std::cout); std::cout << std::endl;

    // test infanterie
    Infanterie I(50, 16, 10);
    I.sortieFlux(std::cout); std::cout << std::endl;

    return 0;
}
