# HEX WARS

## DESCRIPTION
Hex Wars est un jeu de stratégie hexagonal au tour par tour. L'objectif est de réduire les unités de son adversaire à moins de 10% de l'effectif initial.

## COMPILATION 
Afin de pouvoir compiler et lancer le jeu, assurez-vous d'avoir installé **Qt 6.2 (ou supérieur)** avec les modules suivants : 
- **Qt Quick** (inclut les Controls)
- **Qt Multimedia**
- **Qt Linguist Tools** (pour la gestion des langues)
- **OpenGL** (pilotes graphiques à jour)

> 💡 **Note :** Si vous utilisez **Qt Creator** et que vous configurez un Kit avec une version de Qt 6 récente, la grande majorité de ces dépendances seront déjà installées et configurées automatiquement.

## STRUCTURE

``` text
  ./
├── interface/
│   ├── composantsChoixGuerre/
│   │   └── BoutonChoixGuerre.qml
│   ├── composantsJeu/
│   │   ├── BoutonChoix.qml
│   │   ├── BoutonMenu.qml
│   │   ├── LayoutMenu.qml
│   │   ├── Legende.qml
│   │   ├── LigneLegende.qml
│   │   ├── PopupGeneral.qml
│   │   ├── PopupQuitter.qml
│   │   ├── PopupRegles.qml
│   │   └── PopupVictoire.qml
│   ├── composantsMenuPrincipal/
│   │   └── BoutonMenuPrincipal.qml
│   ├── composantsParametres/
│   │   ├── CheckBoxVolume.qml
│   │   ├── ParametresLangue.qml
│   │   ├── ParametresVolume.qml
│   │   └── SliderVolume.qml
│   ├── divers/
│   │   └── Background.qml
│   ├── langues/
│   │   ├── langagemanager.cpp
│   │   ├── langagemanager.h
│   │   └── traduction_en_UK.ts
│   ├── main.qml
│   ├── modelePourQML/
│   │   ├── modelepourqml.cpp
│   │   └── modelepourqml.h
│   ├── openGL/
│   │   ├── HexConfig.h
│   │   ├── MonOpenGLItem.cpp
│   │   ├── MonOpenGLItem.h
│   │   ├── MonRenderer.cpp
│   │   └── MonRenderer.h
│   ├── pages/
│   │   ├── Credits.qml
│   │   ├── MenuPrincipal.qml
│   │   ├── PageChoixGuerre.qml
│   │   ├── PageJeu.qml
│   │   └── Parametres.qml
│   └── ressources/
│       ├── artillerie.png
│       ├── attaquer.wav
│       ├── bombardier.png
│       ├── bouton.wav
│       ├── char.png
│       ├── chasseur.png
│       ├── difficile.png
│       ├── facile.png
│       ├── france.png
│       ├── fregate.png
│       ├── genie.png
│       ├── infanterie.png
│       ├── infirmerie.png
│       ├── moyen.png
│       ├── munitions.png
│       ├── pont.png
│       ├── provisions.png
│       ├── ressources.qrc
│       ├── royaumeuni.png
│       ├── sousmarin.png
│       ├── victoire.wav
│       └── warzone.mp3
├── main.cc
└── modele/
    ├── carte/
    │   ├── carte.cc
    │   ├── carte.hh
    │   ├── createurcases.cc
    │   ├── createurcases.hh
    │   ├── createurunites.cc
    │   ├── createurunites.hh
    │   ├── lecteur.cc
    │   └── lecteur.hh
    ├── cases/
    │   ├── case.cc
    │   ├── case.hh
    │   ├── casemarine.cc
    │   ├── casemarine.hh
    │   ├── caseterrestre.cc
    │   ├── caseterrestre.hh
    │   ├── position.cc
    │   └── position.hh
    ├── constructions/
    │   ├── construction.cc
    │   ├── construction.hh
    │   ├── depotmunitions.cc
    │   ├── depotmunitions.hh
    │   ├── depotprovisions.cc
    │   ├── depotprovisions.hh
    │   ├── infirmerie.cc
    │   ├── infirmerie.hh
    │   ├── pont.cc
    │   └── pont.hh
    ├── data/
    │   ├── guerre0/
    │   │   ├── cases.txt
    │   │   └── unites.txt
    │   ├── guerre1/
    │   │   ├── cases.txt
    │   │   └── unites.txt
    │   └── guerre2/
    │       ├── cases.txt
    │       └── unites.txt
    ├── modele.cc
    ├── modele.hh
    ├── unites/
    │   ├── artillerie.cc
    │   ├── artillerie.hh
    │   ├── bombardier.cc
    │   ├── bombardier.hh
    │   ├── charassaut.cc
    │   ├── charassaut.hh
    │   ├── chasseur.cc
    │   ├── chasseur.hh
    │   ├── fregate.cc
    │   ├── fregate.hh
    │   ├── genie.cc
    │   ├── genie.hh
    │   ├── infanterie.cc
    │   ├── infanterie.hh
    │   ├── sousmarin.cc
    │   └── sousmarin.hh
    └── unitesabstraites/
        ├── uniteaerienne.cc
        ├── uniteaerienne.hh
        ├── unite.cc
        ├── unite.hh
        ├── unitelegere.cc
        ├── unitelegere.hh
        ├── unitelourde.cc
        ├── unitelourde.hh
        ├── unitemarine.cc
        ├── unitemarine.hh
        ├── uniteterrestre.cc
        ├── uniteterrestre.hh
        ├── uniteterrestrelegere.cc
        ├── uniteterrestrelegere.hh
        ├── uniteterrestrelourde.cc
        └── uniteterrestrelourde.hh
```
