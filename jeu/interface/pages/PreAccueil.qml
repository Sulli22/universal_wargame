import QtQuick
import QtQuick.Window

Item {
    id: racinePreAccueil
    signal animationTerminee()

    visible: true

    Rectangle {
        id: background
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
                duration: 1000
                onFinished: racinePreAccueil.animationTerminee()
            }
        }



    }

}
