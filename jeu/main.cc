#include "carte.hh"
#include <iostream>

int main()
{
    // init carte
    Carte carte(0);

    // affichage
    carte.soriteFlux(std::cout);
    carte.afficherDetails(std::cout);

    // cases atteignables et pathfinding
    auto dep = carte.accesCase({0, 9});

    auto unite = dep->getUnite(0);
    std::cout << std::endl; unite->sortieFlux(std::cout); std::cout << std::endl;

    auto casesAtteignables = carte.getCasesAtteignables(dep, unite);
    for (const auto &elt : casesAtteignables) {
        elt.first->sortieFlux(std::cout);
        std::cout << "(" << elt.second << ") -> ";

        for (const auto &c : carte.getChemin(dep, elt.first, unite)) {
            c->sortieFlux(std::cout);
            std::cout <<  " ";
        }

        std::cout << std::endl;
    }

    // ZOC
    std::cout << std::endl;

    auto zoc = carte.getZOC();
    for (auto const &elt : zoc) {
        elt.first->sortieFlux(std::cout);
        for (const auto &faction : elt.second) {
            std::string f;
            switch (faction) {
            case Faction::bleu: f = "bleu"; break;
            case Faction::rouge: f = "rouge"; break;
            case Faction::neutre: f = "neutre"; break;
            }
            std::cout << " " << f;
        }
        std::cout << std::endl;
    }

    return 0;
}
