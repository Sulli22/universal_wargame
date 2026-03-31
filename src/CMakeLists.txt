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

    #camp.cc
    graphe/sommet.cc
    graphe/sommetterrestre.cc
    graphe/sommetmarin.cc
    #graphe/arete.cc
    graphe/matriceadjacence.cc
    graphe/graphe.cc
    cases/case.hh cases/case.cc
    carte/carte.hh carte/carte.cc
    cases/position.hh cases/position.cc
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

    #camp.hh
    graphe/sommet.hh
    graphe/sommetterrestre.hh
    graphe/sommetmarin.hh
    #graphe/arete.hh
    graphe/matriceadjacence.hh
    graphe/graphe.hh
)

target_include_directories(${PROJECT_NAME} PRIVATE
    unitesabstraites
    unites

    graphe

    cases
    carte
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
