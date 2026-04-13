#include "carte.hh"
#include <iostream>

int main()
{
    // init carte
    Carte carte(0);

    // affichage
    carte.soriteFlux(std::cout);
    carte.afficherDetails(std::cout);

    // deplacement test
    auto dep = carte.accesCase({0, 9});
    auto arrivee = carte.accesCase({0, 8});
    dep->deplacerUnite(0, arrivee);

    carte.afficherDetails(std::cout);

    return 0;
}
