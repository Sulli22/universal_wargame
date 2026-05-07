import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import MonGL 1.0
import "../composantsJeu"

Item {
    id: racineJeu

    readonly property string couleur: "#2f3640"
    readonly property real largeurRectangle: Math.max(10, racine.width*0.025)

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

                background: Rectangle {
                    color: parent.hovered ? "#d6d6d6" : "#2C3E50"
                    border.color: "#c5b358"
                    border.width: 2
                }

                Layout.preferredWidth: racineJeu.largeurRectangle
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
                        text: qsTr("Aide") + langageManager.chaineVide
                        onTriggered: {
                            legende.open()
                        }
                    }

                    MenuItem {
                        text: qsTr("Paramètres") + langageManager.chaineVide
                        onTriggered: {
                            parametreJeu.visible = true
                        }
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
                            stats.text = modeleQML.getStatsUniteSelectionee() // Fonctionne que si on clique sur des bonnes cases
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
                        spacing: 10


                        Text {
                            id: stats
                            color: racine.couleurTexte
                            Layout.alignment: Qt.AlignHCenter
                            horizontalAlignment: Text.AlignHCenter
                        }

                        Item {
                            Layout.fillHeight: true
                        }

                        BoutonAction {
                            id: action1
                            text: "Déplacer"
                            Layout.fillWidth: true
                            Layout.preferredHeight: layoutMenu.height * 0.05
                            Layout.rightMargin: 5
                            Layout.leftMargin: 5
                            equipe: modeleQML.getFactionAttaquante()
                        }

                        BoutonAction {
                            id: action2
                            text: "Attaquer"
                            Layout.fillWidth: true
                            Layout.preferredHeight: layoutMenu.height * 0.05
                            Layout.rightMargin: 5
                            Layout.leftMargin: 5
                            equipe: modeleQML.getFactionAttaquante()
                        }

                        BoutonAction {
                            id: action3
                            text: "Construire"
                            Layout.fillWidth: true
                            Layout.preferredHeight: layoutMenu.height * 0.05
                            Layout.rightMargin: 5
                            Layout.leftMargin: 5
                            equipe: modeleQML.getFactionAttaquante()
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
                                modeleQML.changementJoueur()
                                stats.text = ""
                                plateau.update()
                            }
                        }
                    }
                }
            }
        }


        /*
        RowLayout {
            id: basPage
            Layout.fillWidth: true
            Layout.preferredHeight: racineJeu.largeurRectangle
            Layout.maximumHeight: racineJeu.largeurRectangle

            Rectangle {
                color: couleur
                Layout.fillWidth: true
                Layout.preferredHeight: racineJeu.largeurRectangle
            }
        }*/
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
