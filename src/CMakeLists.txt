cmake_minimum_required(VERSION 3.16)

project(src LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cc

    unites/unite.cc
    unites/unitelegere.cc
    unites/unitelourde.cc

    unites/uniteterrestre.cc
    unites/uniteterrestrelegere.cc
    unites/uniteterrestrelourde.cc
    unites/unitemarine.cc
    unites/uniteaerienne.cc

    unites/infanterie.cc
    unites/sousmarin.cc

    #camp.cc
    graphe/sommet.cc
    graphe/sommetterrestre.cc
    graphe/sommetmarin.cc
    #graphe/arete.cc
    graphe/matriceadjacence.cc
    graphe/graphe.cc
)

target_sources(${PROJECT_NAME} PRIVATE
    unites/unite.hh
    unites/unitelegere.hh
    unites/unitelourde.hh

    unites/uniteterrestre.hh
    unites/uniteterrestrelegere.hh
    unites/uniteterrestrelourde.hh
    unites/unitemarine.hh
    unites/uniteaerienne.hh

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
    unites
    graphe
)

add_compile_options(
    -Wall
    -Wpedantic
    -Wextra
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
