cmake_minimum_required(VERSION 3.16)

project(jeu LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Wall
    -Wpedantic
    -Wextra
)

file(COPY modele/data DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME}
    main.cc

    modele/unitesabstraites/unite.cc
    modele/unitesabstraites/unitelegere.cc
    modele/unitesabstraites/unitelourde.cc
    modele/unitesabstraites/uniteterrestre.cc
    modele/unitesabstraites/uniteterrestrelegere.cc
    modele/unitesabstraites/uniteterrestrelourde.cc
    modele/unitesabstraites/unitemarine.cc
    modele/unitesabstraites/uniteaerienne.cc

    modele/unites/infanterie.cc
    modele/unites/sousmarin.cc
    modele/unites/genie.cc
    modele/unites/bombardier.cc
    modele/unites/chasseur.cc
    modele/unites/fregate.cc
    modele/unites/charassaut.cc
    modele/unites/artillerie.cc

    modele/constructions/construction.cc
    modele/constructions/infirmerie.cc
    modele/constructions/depotprovisions.cc
    modele/constructions/pont.cc
    modele/constructions/depotmunitions.cc

    modele/cases/case.cc
    modele/cases/position.cc
    modele/cases/casemarine.cc
    modele/cases/caseterrestre.cc
    
    modele/carte/carte.cc
    modele/carte/lecteur.cc
    modele/carte/createurcases.cc
    modele/carte/createurunites.cc

    modele/modele.cc
)

target_sources(${PROJECT_NAME} PRIVATE
    modele/unitesabstraites/unite.hh
    modele/unitesabstraites/unitelegere.hh
    modele/unitesabstraites/unitelourde.hh
    modele/unitesabstraites/uniteterrestre.hh
    modele/unitesabstraites/uniteterrestrelegere.hh
    modele/unitesabstraites/uniteterrestrelourde.hh
    modele/unitesabstraites/unitemarine.hh
    modele/unitesabstraites/uniteaerienne.hh

    modele/unites/infanterie.hh
    modele/unites/sousmarin.hh
    modele/unites/genie.hh
    modele/unites/bombardier.hh
    modele/unites/chasseur.hh
    modele/unites/fregate.hh
    modele/unites/charassaut.hh
    modele/unites/artillerie.hh

    modele/constructions/construction.hh
    modele/constructions/infirmerie.hh
    modele/constructions/depotprovisions.hh
    modele/constructions/pont.hh
    modele/constructions/depotmunitions.hh

    modele/cases/case.hh
    modele/cases/position.hh
    modele/cases/casemarine.hh
    modele/cases/caseterrestre.hh

    modele/carte/carte.hh
    modele/carte/lecteur.hh
    modele/carte/createurcases.hh
    modele/carte/createurunites.hh

    modele/modele.hh
)

target_include_directories(${PROJECT_NAME} PRIVATE
    modele/unitesabstraites
    modele/unites
    modele/constructions
    modele/cases
    modele/carte
    modele/data
    modele
)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
