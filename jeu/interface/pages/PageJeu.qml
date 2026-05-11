import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import MonGL 1.0
import "../composantsJeu"

Item {
    id: racineJeu

    readonly property string couleur: "#2f3640"
    readonly property real largeurRectangle: Math.max(10, racine.width*0.025)
    property string equipeAttaquante: ""
    property int nbConstructionsPossibles: 0
    property int nbActionsPossibles: 0

    Component.onCompleted: {
        if (modeleQML) {
            equipeAttaquante = modeleQML.getFactionAttaquante()
            nbActionsPossibles = modeleQML.getNbActionsPossibles()
        }
    }

    signal retourMenuPrincipal(bool fenetre)

    ColumnLayout {
        id: layoutGeneral
        anchors.fill: parent
        spacing: 0
        anchors.margins: 0

        RowLayout {
            id: hautPage
            spacing: 0
            Layout.fillWidth: true
            Layout.preferredHeight: racineJeu.largeurRectangle
            Layout.maximumHeight: racineJeu.largeurRectangle

            Button {
                id: boutonAutre
                text: "="
                palette.buttonText: racine.couleurTexte
                Layout.preferredWidth: racineJeu.largeurRectangle
                Layout.fillHeight: true
                font.pointSize: Math.max(implicitWidth*0.4, 10)
                font.bold: true

                background: Rectangle {
                    color: parent.hovered ? "#d6d6d6" : "#2C3E50"
                    border.color: "#c5b358"
                    border.width: 2
                }

                onClicked: {
                    menuAutre.open()
                }

                Menu {
                    id: menuAutre
                    y: boutonAutre.height

                    MenuItem {
                        text: qsTr("Aide") + langageManager.chaineVide

                        onTriggered: legende.open()
                    }

                    MenuItem {
                        text: qsTr("Paramètres") + langageManager.chaineVide

                        onTriggered: parametreJeu.visible = true
                    }

                    MenuItem {
                        text: qsTr("Quitter la partie") + langageManager.chaineVide

                        onTriggered: {
                            confirmationQuitter.fenetre = false
                            confirmationQuitter.open()
                            rectangleOpacite.visible = true
                        }
                    }
                }
            }

            Rectangle {
                color: couleur
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            Button {
                id: boutonQuitter
                text: "X"
                padding: 0
                Layout.alignment: Qt.AlignRight
                Layout.fillHeight: true
                Layout.preferredWidth: racineJeu.largeurRectangle

                background: Rectangle {
                    gradient: Gradient {
                        orientation: Gradient.Horizontal
                        GradientStop { position: 0.0; color: "red" }
                        GradientStop { position: 0.5; color: "#de7307" }
                        GradientStop { position: 1.0; color: "red" }
                    }
                }

                onClicked: {
                    confirmationQuitter.fenetre = true
                    confirmationQuitter.open()
                    rectangleOpacite.visible = true
                }
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            RowLayout {
                id: milieuPage
                anchors.fill: parent
                spacing: 0

                MonOpenGLItem {
                    id: plateau
                    modele: modeleQML
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    MouseArea {
                        id: zoneClique
                        anchors.fill: parent

                        onClicked: (mouse) => {
                            plateau.gererClic(mouse.x, mouse.y)
                            stats.text = modeleQML.getStatsUniteSelectionee()
                            nbActionsPossibles = modeleQML.getNbActionsPossibles()
                            nbConstructionsPossibles = modeleQML.getNbConstructionsPossibles()
                            boutonValider.enabled = modeleQML.actionValidable()
                            boutonAnnuler.enabled = modeleQML.actionAnnulable()
                        }
                    }
                }

                Rectangle {
                    id: coteDroit
                    color: couleur
                    Layout.fillHeight: true
                    Layout.preferredWidth: racineJeu.largeurRectangle * 5

                    Rectangle {
                        anchors.top: parent.top
                        color: "black"
                        width: parent.width
                        height: 2
                    }

                    ColumnLayout {
                        id: layoutMenu
                        anchors.fill: parent
                        spacing: 3

                        Label {
                            id: labelJoueur
                            text: qsTr("Joueur : ") + langageManager.chaineVide
                            font.pointSize: 18
                            font.bold: true
                            color: racine.couleurTexte
                            Layout.fillWidth: true
                            horizontalAlignment: Text.AlignHCenter
                        }

                        Rectangle {
                            id: couleurJoueur
                            color: racineJeu.equipeAttaquante
                            Layout.preferredWidth: layoutMenu.width * 0.5
                            Layout.preferredHeight: layoutMenu.height * 0.05
                            Layout.alignment: Qt.AlignHCenter
                            border.color: racine.couleurTexte

                            Behavior on color {
                                ColorAnimation {
                                    duration: 1000
                                }
                            }
                        }

                        Rectangle {
                            color: "black"
                            Layout.fillWidth: true
                            Layout.preferredHeight: 5
                        }

                        ColumnLayout {
                            id: layoutStat
                            spacing: 0

                            Label {
                               id: labelStats
                               text: qsTr("Stats Unité") + langageManager.chaineVide
                               color: racine.couleurTexte
                               Layout.fillWidth: true
                               horizontalAlignment: Text.AlignHCenter
                               font.pointSize: 18
                               font.bold: true
                            }

                            Text {
                               id: stats
                               text: qsTr("Pas d'unité") + langageManager.chaineVide
                               color: racine.couleurTexte
                               Layout.fillWidth: true
                               horizontalAlignment: Text.AlignHCenter
                               font.pointSize: 18
                            }
                        }

                        Rectangle {
                            color: "black"
                            Layout.fillWidth: true
                            Layout.preferredHeight: 5
                        }

                        Label {
                            id: labelConstructions
                            text: qsTr("Constructions") + langageManager.chaineVide
                            color: racine.couleurTexte
                            Layout.alignment: Qt.AlignHCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 18
                            font.bold: true
                        }

                        ColumnLayout {
                            id: layoutConstructions
                            spacing: 8

                            BoutonAction {
                                id: depotMunitions
                                text: qsTr("Munitions") + langageManager.chaineVide
                                equipe: racineJeu.equipeAttaquante
                                enabled: nbConstructionsPossibles === 3

                                onClicked: {
                                    modeleQML.choixConstruction(0)
                                    boutonValider.enabled = modeleQML.actionValidable()
                                }
                            }

                            BoutonAction {
                                id: depotProvisions
                                text: qsTr("Provisions") + langageManager.chaineVide
                                equipe: racineJeu.equipeAttaquante
                                enabled: nbConstructionsPossibles === 3

                                onClicked: {
                                    modeleQML.choixConstruction(1)
                                    boutonValider.enabled = modeleQML.actionValidable()
                                }
                            }

                            BoutonAction {
                                id: infirmerie
                                text: qsTr("Infirmerie") + langageManager.chaineVide
                                equipe: racineJeu.equipeAttaquante
                                enabled: nbConstructionsPossibles === 3

                                onClicked: {
                                    modeleQML.choixConstruction(2)
                                    boutonValider.enabled = modeleQML.actionValidable()
                                }
                            }

                            BoutonAction {
                                id: pont
                                text: qsTr("Pont") + langageManager.chaineVide
                                equipe: racineJeu.equipeAttaquante
                                enabled: nbConstructionsPossibles === 1

                                onClicked: {
                                    modeleQML.choixConstruction(3)
                                    boutonValider.enabled = modeleQML.actionValidable()
                                }
                            }
                        }

                        Rectangle {
                            color: "black"
                            Layout.fillWidth: true
                            Layout.preferredHeight: 5
                        }

                        ColumnLayout {
                            id: layoutActions
                            spacing: 8

                            BoutonAction {
                                id: deplacer
                                text: qsTr("Déplacer") + langageManager.chaineVide
                                equipe: racineJeu.equipeAttaquante
                                enabled:  nbActionsPossibles >= 2

                                onClicked: {
                                    racine.lancerBruitBouton()
                                    modeleQML.choixAction(0);
                                    plateau.update();
                                }
                            }

                            BoutonAction {
                                id: attaquer
                                text: qsTr("Attaquer") + langageManager.chaineVide
                                equipe: racineJeu.equipeAttaquante
                                enabled: nbActionsPossibles >= 2

                                onClicked: {
                                    racine.lancerBruitBouton()
                                    modeleQML.choixAction(1);
                                    plateau.update();
                                }
                            }

                            BoutonAction {
                                id: construire
                                text: qsTr("Construire") + langageManager.chaineVide
                                equipe: racineJeu.equipeAttaquante
                                enabled: nbActionsPossibles === 3

                                onClicked: {
                                    racine.lancerBruitBouton()
                                    modeleQML.choixAction(2);
                                    plateau.update();
                                }
                            }

                            RowLayout {
                                id: layoutValidation
                                Layout.alignment: Qt.AlignBottom
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                Layout.maximumHeight: layoutMenu.height * 0.05
                                Layout.rightMargin: 5
                                Layout.leftMargin: 5

                                BoutonChoix {
                                    id: boutonAnnuler
                                    text: "✗"
                                    couleurExtremiteGradient: "red"
                                    couleurCentreGradient: "#de7307"
                                    enabled: false

                                    onClicked: {
                                        modeleQML.annulerSelections()
                                        enabled = false
                                        stats.text = modeleQML.getStatsUniteSelectionee()
                                        nbActionsPossibles = 0
                                        nbConstructionsPossibles = 0
                                        plateau.update()
                                    }
                                }

                                BoutonChoix {
                                    id: boutonValider
                                    text: "✔"
                                    couleurExtremiteGradient: "green"
                                    couleurCentreGradient: "#95ff80"
                                    enabled: false

                                    onClicked: {
                                        modeleQML.effectuerAction()
                                        enabled = false
                                        boutonAnnuler.enabled = false
                                        racineJeu.equipeAttaquante = modeleQML.getFactionAttaquante()
                                        nbActionsPossibles = 0
                                        nbConstructionsPossibles = 0
                                        plateau.update()
                                    }
                                }
                            }
                        }

                        Rectangle {
                            color: "black"
                            Layout.fillWidth: true
                            Layout.preferredHeight: 5
                        }

                        BoutonAction {
                            id: changerJoueur
                            text: qsTr("Joueur suivant")
                            Layout.fillWidth: true
                            Layout.preferredHeight: layoutMenu.height*0.05
                            Layout.bottomMargin: 10
                            Layout.rightMargin: 5
                            Layout.leftMargin: 5

                            onClicked: {
                                racine.lancerBruitBouton()
                                modeleQML.changerJoueur()
                                stats.text = "Pas d'unite"
                                racineJeu.equipeAttaquante = modeleQML.getFactionAttaquante()
                                nbActionsPossibles = 0
                                plateau.update()
                            }
                        }
                    }
                }
            }
        }
    }

    PopupRegles {
        id: regles

        Component.onCompleted: open()
    }

    Parametres {
        id: parametreJeu
        visible: false

        onBoutonRetourClique: visible = false
    }

    Rectangle {
        id: rectangleOpacite
        color: "grey"
        opacity: 0.2
        anchors.fill: parent
        visible: false
    }

    PopupQuitter {
        id: confirmationQuitter

        onRetourMenuPrincipalPopup: racineJeu.retourMenuPrincipal(fenetre)
    }

    Legende {
        id: legende
    }
}
