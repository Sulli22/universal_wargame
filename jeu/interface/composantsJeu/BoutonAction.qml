import QtQuick 2.15
import QtQuick.Controls

Button {
    id: racineBoutonAction

    property alias equipe: backgroundBoutonAction.color
    property bool selectionnable: true

    width: parent.width * 0.2
    height: parent.height * 0.2
    font.pointSize: Math.max(height * 0.4, 12)
    font.bold: true
    clip: true
    enabled: selectionnable
    opacity: selectionnable ? 1 : 0.2

    palette.buttonText: "#A9A9A9"

    background: Rectangle {
        id: backgroundBoutonAction
        radius: height/2

        Behavior on color {
            ColorAnimation {
                duration: 1000
            }
        }
    }
}
