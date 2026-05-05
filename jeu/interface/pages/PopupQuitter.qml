import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Popup {
    id: racinePopup

    property bool fenetre: true
    signal retourMenuPrincipalPopup()

    anchors.centerIn: parent
    width: parent.width*0.3
    height: parent.height*0.3
    modal: true
    closePolicy:  Popup.NoAutoClose
    background: Rectangle {
        radius: height/4
        gradient: Gradient {
            orientation: Gradient.Vertical
            GradientStop {position: 0.0; color:"grey"}
            GradientStop {position: 1.0; color: "#ffffff"}
        }
    }

    ColumnLayout {
        id: layoutPopup
        anchors.centerIn: parent

        Label {
            id: labelQuitter
            text: racinePopup.fenetre ? qsTr("Voulez vous vraiment quitter le jeu ?") + languageManager.chaineVide: qsTr("Voulez vous vraiment quitter la partie?") + languageManager.chaineVide
            color: "black"
            font.pointSize: 20
            font.bold: true
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            Button {
                text: qsTr("Quitter") + languageManager.chaineVide
                palette.buttonText: "black"
                Layout.preferredWidth: racinePopup.width*0.2
               // Layout.alignment: Qt.AlignHCenter
                onClicked: racinePopup.retourMenuPrincipalPopup()

                font.bold: true
                background: Rectangle {
                    radius: height/2
                    gradient: Gradient {
                        orientation: Gradient.Horizontal
                        GradientStop {position: 0.0; color:"red"}
                        GradientStop {position: 0.5; color: "#de7307"}
                        GradientStop {position: 1.0; color: "red"}
                    }
                }
            }

            Button {
                text: qsTr("Annuler") + languageManager.chaineVide
                palette.buttonText: "black"
                Layout.preferredWidth: racinePopup.width*0.2
                font.bold: true
                onClicked: {
                    close()
                    rectangleOpacite.visible = false
                }
                background: Rectangle {
                    radius: height/2
                }
            }
        }
    }
}
