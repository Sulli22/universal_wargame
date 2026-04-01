#include "carte.hh"
#include "infanterie.hh"
#include "sousmarin.hh"
#include "bombardier.hh"
#include "constructeur.hh"
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

    // test carte et voisins
    Carte carte(3, 3);
    carte.soriteFlux(std::cout);
    for (int q = 0; q < (int)carte.getLargeur(); ++q) {
        for (int r = 0; r < (int)carte.getHauteur(); ++r) {
            auto c = carte.accesCase({q, r});
            auto voisins = carte.getVoisins(*c);
            std::cout << "Voisins de (" << q << "," << r << ") : ";
            for (const auto &v : voisins) {
                v.getPos().sortieFlux(std::cout);
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    // test unites
    Infanterie I;
    I.sortieFlux(std::cout); std::cout << std::endl;

    SousMarin SM;
    SM.sortieFlux(std::cout); std::cout << std::endl;

    Bombardier B;
    B.sortieFlux(std::cout); std::cout << std::endl;

    Constructeur C;
    C.sortieFlux(std::cout); std::cout << std::endl;

    return 0;
}
