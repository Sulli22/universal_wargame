import QtQuick
import QtQuick.Layouts

Item {
    id: racineBoutonChoixGuerre

    signal clique()

    property alias sourceImage: imageFond.source
    property alias nomGuerre: labelGuerre.text

    Layout.fillWidth: true

    Rectangle {
        color: "transparent"
        anchors.fill: parent

        Image {
            id: imageFond
            width: parent.width
            height: parent.height
            fillMode: Image.PreserveAspectCrop
            anchors.fill: parent

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true

                onEntered: {
                    rectangleTemp.visible = true
                }

                onExited: {
                    rectangleTemp.visible = false
                }

                onClicked: racineBoutonChoixGuerre.clique()
            }
        }

        Rectangle {
            id: rectangleTemp
            anchors.fill: parent
            anchors.centerIn: parent
            color: "grey"
            opacity: 0.5
            visible: false
        }
    }

    Text {
        id: labelGuerre
        anchors.centerIn: parent
        font.pointSize: Math.max(1,parent.height/4)
        color: "white"
        font.bold: true
    }
}
