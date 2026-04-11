#include "carte.hh"
#include <iostream>

int main()
{
    // test carte et voisins
    Carte carte(0);
    carte.soriteFlux(std::cout);
    carte.afficherDetails(std::cout);

    return 0;
}
