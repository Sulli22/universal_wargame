import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import MonGL 1.0
import "../composantsJeu"

Item {
    id: racineJeu

    readonly property string couleur: "#2f3640"
    readonly property real largeurRectangle: Math.max(10, racine.width*0.025)
    signal retourAccueil(bool fenetre)
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
                background: Rectangle {
                    color: parent.hovered ? "#d6d6d6" : "#2C3E50"
                    border.color: "#c5b358"
                    border.width: 2
                }

                Layout.preferredWidth: hautPage.width
                Layout.fillHeight: true
                font.pointSize: Math.max(implicitWidth*0.4, 10)
                font.bold: true

                onClicked: {
                    menuAutre.open()

                }
                Menu {
                    id: menuAutre
                    y: boutonAutre.height

                    MenuItem {
                        text: "Paramètres"
                        onTriggered: {
                            parametreJeu.visible = true
                        }
                    }

                    MenuItem {
                        text: "Quitter la partie"
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
                background: Rectangle {
                    gradient: Gradient {
                        orientation: Gradient.Horizontal
                        GradientStop {position: 0.0; color:"red"}
                        GradientStop {position: 0.5; color: "#de7307"}
                        GradientStop {position: 1.0; color: "red"}
                    }
                }
                Layout.fillHeight: true
                Layout.preferredWidth: racineJeu.largeurRectangle
                onClicked: {
                    confirmationQuitter.fenetre = true
                    confirmationQuitter.open()
                    rectangleOpacite.visible = true
                }
            }
        }

        RowLayout {
            id: milieuPage
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            MonOpenGLItem {
                id: plateau
                Layout.fillHeight: true
                Layout.fillWidth: true

                MouseArea {
                    id: zoneClique
                    anchors.fill: parent
                    onClicked: {
                        console.log("("+mouseX+","+mouseY+")")
                    }
                }
            }

            Rectangle {
                id: coteDroit
                color: couleur
                Layout.fillHeight: true
                Layout.preferredWidth: racineJeu.largeurRectangle * 4


                Rectangle {
                    anchors.top: parent.top
                    color: "black"
                    width: parent.width
                    height: 2
                }

                Rectangle {
                    anchors.bottom: parent.bottom
                    color: "black"
                    width: parent.width
                    height: 2
                }

                ColumnLayout {
                    id: layoutMenu
                    anchors.fill: parent
                    spacing: 10

                    Item {
                        Layout.fillHeight: true
                    }

                    BoutonAction {
                        id: action1
                        text: "Action 1"
                        Layout.fillWidth: true
                        Layout.preferredHeight: layoutMenu.height * 0.05
                        Layout.rightMargin: 5
                        Layout.leftMargin: 5
                        equipe: "red"
                    }

                    BoutonAction {
                        id: action2
                        text: "Action 2"
                        Layout.fillWidth: true
                        Layout.preferredHeight: layoutMenu.height * 0.05
                        Layout.rightMargin: 5
                        Layout.leftMargin: 5
                        equipe: "red"
                    }

                    BoutonAction {
                        id: action3
                        text: "Action 3"
                        Layout.fillWidth: true
                        Layout.preferredHeight: layoutMenu.height * 0.05
                        Layout.bottomMargin: 10
                        Layout.rightMargin: 5
                        Layout.leftMargin: 5
                        equipe: "red"
                    }
                }

            }
        }

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
        onRetourAccueilPopup: racineJeu.retourAccueil(fenetre)
    }
}
