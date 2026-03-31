#include "graphe.hh"
#include "carte.hh"
#include "infanterie.hh"
#include "sousmarin.hh"
#include <iostream>

int main()
{
    // test graphe
    /*MatriceAdjacence m(4, 5);
    Graphe g(m);
    g.sortieFlux(std::cout); std::cout << std::endl;

    for (auto s : g.getSommets()) {
        std::cout<<"Voisins de "<<s->getId()<<" : ";
           g.voisins(s); std::cout << std::endl;
    }*/

    // test carte
    Carte carte(3, 3);
    carte.soriteFlux(std::cout);

    // test infanterie
    Infanterie I;
    I.sortieFlux(std::cout); std::cout << std::endl;

    // test sous-marin
    SousMarin SM;
    SM.sortieFlux(std::cout); std::cout << std::endl;

    return 0;
}
