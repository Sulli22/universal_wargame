cmake_minimum_required(VERSION 3.16)

project(src LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cc

    unite.cc
    unitelegere.cc
    unitelourde.cc

    uniteterrestrelegere.cc
    unitemaritime.cc
    uniteaerienne.cc

    camp.cc
    sommet.cc
    sommetterrestre.cc
    sommetmaritime.cc
    arete.cc
    uniteterrestrelourde.cc
)

target_sources(${PROJECT_NAME} PRIVATE
    unite.hh
    unitelegere.hh
    unitelourde.hh

    uniteterrestrelegere.hh
    uniteterrestrelourde.hh
    unitemaritime.hh
    uniteaerienne.hh

    camp.hh
    sommet.hh
    sommetterrestre.hh
    sommetmaritime.hh
    arete.hh
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
