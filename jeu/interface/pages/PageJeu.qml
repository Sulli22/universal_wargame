import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

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
                text: "Paramètres"
                palette.buttonText: "#f5f5dc"
                background: Rectangle {
                    color: couleur
                }
                Layout.fillHeight: true
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
                    color: "red"
                }
                Layout.fillHeight: true
                Layout.preferredWidth: racineJeu.largeurRectangle
                onClicked: Qt.quit()
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

            // Cette partie deviendra le plateau de jeu
            Item {
                id:plateau
                Layout.fillHeight: true
                Layout.fillWidth: true
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

}

