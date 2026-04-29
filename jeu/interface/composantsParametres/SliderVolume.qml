import QtQuick
import QtQuick.Controls

Item {
    Slider {
        id: slider
        from: 0
        to: 100
        value: racine.volumeBouton * 100
        height: 50
        stepSize: 1
        width: parent.width
        onMoved: {
            racine.volumeBouton = slider.value/100
            racine.volumeMusique = slider.value/200
        }

        background: Rectangle {
            x: slider.leftPadding
            y: slider.topPadding + slider.availableHeight/2 - height/2
            implicitWidth: 200
            implicitHeight: 20
            width: slider.availableWidth
            height:  implicitHeight
            radius: height/2
            color: racine.couleurTexte

            Rectangle {
                width: slider.visualPosition === 0 ? 0 : slider.handle.x + slider.handle.width/2
                height: parent.height
                color: "blue"
                radius: height/2
            }
        }

        handle: Rectangle {
            x:slider.leftPadding + slider.visualPosition*(slider.availableWidth - width)
            y: slider.topPadding + slider.availableHeight/2 - height/2
            implicitHeight: 25
            implicitWidth: 25
            radius: implicitWidth/2
        }
    }

    Text {
        id: volumeGlobal
        text: slider.value
        anchors.centerIn: slider
        font.pointSize: slider.height/4
        color: "black"
    }
}
