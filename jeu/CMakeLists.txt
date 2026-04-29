cmake_minimum_required(VERSION 3.16)

project(jeu LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Wall
    -Wpedantic
    -Wextra
)

find_package(Qt6 6.2 COMPONENTS
        Quick QuickControls2 Multimedia Core LinguistTools
        OpenGL
    REQUIRED)

set(PCH_HEADERS
    <QString>
    <QVector>
    <QDebug>
    <QGuiApplication>
    <QQmlApplicationEngine>
    <QTranslator>
    <QQuickStyle>
    <QMediaPlayer>
)

file(COPY interface/ressources/warzone.mp3 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY modele/data DESTINATION ${CMAKE_BINARY_DIR})

qt_add_executable(${PROJECT_NAME}
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

    interface/langues/languagemanager.h
    interface/langues/languageManager.cc
    interface/ressources/images.qrc
    ${QM_FILES}
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

set(TS_FILES interface/langues/traduction_en_UK.ts)
qt_add_translation(QM_FILES ${TS_FILES} )

#qt_policy(SET QTP0004 OLD)
qt6_add_qml_module(${PROJECT_NAME}

    URI ${PROJECT_NAME}
    VERSION 1.0

    QML_FILES
        interface/main.qml
        interface/pages/PreAccueil.qml
        interface/pages/Accueil.qml
        interface/composantsAccueil/BoutonAccueil.qml
        interface/pages/Parametres.qml
        interface/composantsParametres/ParametresVolume.qml
        interface/composantsParametres/ParametresLangue.qml
        interface/composantsParametres/CheckBoxVolume.qml
        interface/composantsParametres/SliderVolume.qml
        interface/pages/PageChoixGuerre.qml
        interface/composantsChoixGuerre/BoutonChoixGuerre.qml
        interface/pages/PageJeu.qml
        interface/divers/Background.qml
    RESOURCE_PREFIX "/qt/qml"
)

target_precompile_headers(${PROJECT_NAME} PRIVATE ${PCH_HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE
    modele/unitesabstraites
    modele/unites
    modele/constructions
    modele/cases
    modele/carte
    modele/data

    interface
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Quick Qt6::QuickControls2 Qt6::Multimedia Qt6::Core
    Qt6::OpenGL)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
