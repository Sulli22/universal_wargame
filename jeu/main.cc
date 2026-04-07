#include "carte.hh"
#include "infanterie.hh"
#include "sousmarin.hh"
#include "bombardier.hh"
#include "constructeur.hh"
#include <iostream>

int main()
{
    // test carte et voisins
    Carte carte("data/map0.txt");
    carte.soriteFlux(std::cout);
    carte.afficherDetails(std::cout);

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
