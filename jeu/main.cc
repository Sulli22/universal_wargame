#include "carte.hh"
#include "infanterie.hh"
#include "sousmarin.hh"
#include "bombardier.hh"
#include "constructeur.hh"
#include <iostream>

int main()
{
    // test carte et voisins
    Carte carte(0);
    carte.soriteFlux(std::cout);
    //carte.afficherDetails(std::cout);

    // test unites
    Infanterie I(Faction::bleu);
    I.sortieFlux(std::cout); std::cout << std::endl;

    SousMarin SM(Faction::bleu);
    SM.sortieFlux(std::cout); std::cout << std::endl;

    Bombardier B(Faction::rouge);
    B.sortieFlux(std::cout); std::cout << std::endl;

    Constructeur C(Faction::rouge);
    C.sortieFlux(std::cout); std::cout << std::endl;

    return 0;
}
