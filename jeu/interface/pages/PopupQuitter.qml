import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Popup {
    id: racinePopup
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
            text: qsTr("Voulez vous vraiment quitter ?") + languageManager.chaineVide
            font.pointSize: 20
            font.bold: true
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            Button {
                text: qsTr("Quitter") + languageManager.chaineVide
               // Layout.alignment: Qt.AlignHCenter
                onClicked: Qt.quit()
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
                text: qsTr("Annuler")
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
