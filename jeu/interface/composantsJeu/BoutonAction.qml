import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: racineBoutonAction

    property alias equipe: backgroundBoutonAction.color

    Layout.fillWidth: true
    Layout.preferredHeight: layoutMenu.height * 0.05
    font.pointSize: Math.max(layoutMenu.height * 0.05* 0.4, 12)
    font.bold: true
    opacity: enabled ? 1 : 0.2

    palette.buttonText: "#A9A9A9"

    background: Rectangle {
        id: backgroundBoutonAction
        radius: layoutMenu.height*0.05/2

        Behavior on color {
            ColorAnimation {
                duration: 1000
            }
        }
    }
}
