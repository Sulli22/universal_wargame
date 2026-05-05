import QtQuick
import QtQuick.Controls

CheckBox {
    id: checkBoxDesactive
    font.bold: true

    indicator: Rectangle {
        implicitWidth: 26
        implicitHeight: 26
        x: checkBoxDesactive.leftPadding
        y: parent.height/2 - height/2
        radius: 3
        border.color: racine.couleurTexte
        color: "transparent"

        Rectangle {
            width: 14
            height: 14
            radius: 2
            anchors.centerIn: parent
            color: racine.couleurTexte
            visible: checkBoxDesactive.checked
        }
    }

    contentItem: Text {
        text: checkBoxDesactive.text
        font: checkBoxDesactive.font
        color: racine.couleurTexte
        verticalAlignment: Text.AlignVCenter
        leftPadding: checkBoxDesactive.indicator.width + checkBoxDesactive.spacing
    }

}

