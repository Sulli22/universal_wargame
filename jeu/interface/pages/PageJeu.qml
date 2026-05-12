import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia

import MonGL 1.0
import "../composantsJeu"

Item {
    id: racineJeu

    readonly property string couleur: "#2f3640"
    readonly property real largeurRectangle: Math.max(10, racine.width*0.025)
    property string equipeAttaquante: ""

    Component.onCompleted: {
        if (modeleQML)
            equipeAttaquante = modeleQML.getFactionAttaquante()
    }

    signal retourMenuPrincipal(bool fenetre)


    function lancerBruitAttaque() {
        let son = composantSonAttaque.createObject(racineJeu)
        son.play()
        son.playbackStateChanged.connect(function() {
            if (son.playbackState === MediaPlayer.StoppedState) {
                son.destroy(500)
               }
           })
    }

    Component {
            id: composantSonAttaque

            MediaPlayer {
                source: "qrc:/attaque"
                audioOutput: AudioOutput {
                    volume: racine.desactiverVolumeBouton ? 0 : racine.volumeBouton / 3
                }
            }
        }

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
                id: partiePrincipale
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

                        onClicked: menu.gererCliqueMouseArea(mouseX, mouseY)
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
                        height: 5
                    }

                    LayoutMenu {
                        id: menu
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

    PopupVictoire {
        id: popupVictoire
    }

}
