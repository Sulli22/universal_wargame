import QtQuick
import QtQuick.Window

Rectangle {
    id: racineCredits
    signal animationTerminee()
    anchors.fill: parent
    color: "black"

    Text {
        id: labelDeveloppePar
        text: "Développé par :\nSullivan Driant\nMasian Huneau"

        font.pointSize: 20
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        ColorAnimation on color{
            from: "white"
            to: "black"
            duration: 3000
            onFinished: racineCredits.animationTerminee()
        }
    }
}


