import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import MonGL 1.0

Item {
    id: racineJeu

    readonly property string couleur: "#2f3640"
    readonly property real largeurRectangle: Math.max(10, racine.width*0.025)

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
                id: boutonParametres
                text: qsTr("Paramètres") + languageManager.chaineVide
                font.bold: true
                palette.buttonText: "#f5f5dc"
                Layout.fillHeight: true

                background: Rectangle {
                    color: couleur
                    border.color: "#f5f5dc"
                    border.width: 1
                }

                onClicked: {
                    parametreJeu.visible = true
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
                    confirmationQuitter.open()
                    rectangleOpacite.visible = true
                }
            }
        }

        RowLayout {
            id: milieuPage
            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                color: couleur
                Layout.fillHeight: true
                Layout.preferredWidth: racineJeu.largeurRectangle
            }

            MonOpenGLItem {
                modele: modeleQML
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
                color: couleur
                Layout.fillHeight: true
                Layout.preferredWidth: racineJeu.largeurRectangle
            }
        }

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
    }
}
