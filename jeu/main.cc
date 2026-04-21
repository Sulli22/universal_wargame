#include "model.hh"
#include <iostream>

int main()
{
    Model monModel(0);

    monModel.sortieFlux(std::cout);

    monModel.selectionnerCase({0, 0});
    std::cout << std::endl << "-> Selection {0, 0}" << std::endl;
    monModel.sortieFlux(std::cout);

    monModel.choixAction(0);
    std::cout << std::endl << "-> Choix action 0" << std::endl;
    monModel.sortieFlux(std::cout);
/*
    monModel.selectionnerCase({0, 0});
    monModel.sortieFlux(std::cout);

    monModel.selectionnerCase({0, 0});
    monModel.sortieFlux(std::cout);*/

    return 0;
}
