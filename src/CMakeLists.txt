cmake_minimum_required(VERSION 3.16)

project(src LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Wall
    -Wpedantic
    -Wextra
)

add_executable(${PROJECT_NAME}
    main.cc

    unitesabstraites/unite.cc
    unitesabstraites/unitelegere.cc
    unitesabstraites/unitelourde.cc
    unitesabstraites/uniteterrestre.cc
    unitesabstraites/uniteterrestrelegere.cc
    unitesabstraites/uniteterrestrelourde.cc
    unitesabstraites/unitemarine.cc
    unitesabstraites/uniteaerienne.cc

    unites/infanterie.cc
    unites/sousmarin.cc
    unites/constructeur.cc
    unites/bombardier.cc

    constructions/construction.cc
    constructions/infirmerie.cc
    constructions/depotprovisions.cc
    constructions/pont.cc
    constructions/depotmunitions.cc

    #camp.cc
    #graphe/sommet.cc
    #graphe/sommetterrestre.cc
    #graphe/sommetmarin.cc
    #graphe/arete.cc
    #graphe/matriceadjacence.cc
    #graphe/graphe.cc
    cases/case.cc
    carte/carte.cc
    cases/position.cc
    cases/casemarine.cc
    cases/caseterrestre.cc

    jeu.cc
)

target_sources(${PROJECT_NAME} PRIVATE
    unitesabstraites/unite.hh
    unitesabstraites/unitelegere.hh
    unitesabstraites/unitelourde.hh
    unitesabstraites/uniteterrestre.hh
    unitesabstraites/uniteterrestrelegere.hh
    unitesabstraites/uniteterrestrelourde.hh
    unitesabstraites/unitemarine.hh
    unitesabstraites/uniteaerienne.hh

    unites/infanterie.hh
    unites/sousmarin.hh
    unites/constructeur.hh
    unites/bombardier.hh

    constructions/construction.hh
    constructions/infirmerie.hh
    constructions/depotprovisions.hh
    constructions/pont.hh
    constructions/depotmunitions.hh

    #camp.hh
    #graphe/sommet.hh
    #graphe/sommetterrestre.hh
    #graphe/sommetmarin.hh
    #graphe/arete.hh
    #graphe/matriceadjacence.hh
    #graphe/graphe.hh

    carte/carte.hh
    cases/case.hh
    cases/position.hh
    cases/casemarine.hh
    cases/caseterrestre.hh

    jeu.hh
)

target_include_directories(${PROJECT_NAME} PRIVATE
    unitesabstraites
    unites

    constructions
    #graphe

    cases
    carte
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
