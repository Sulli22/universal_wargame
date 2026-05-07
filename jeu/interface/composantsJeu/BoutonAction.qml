import QtQuick 2.15
import QtQuick.Controls

Button {
    id: racineBoutonAction

    property alias equipe: backgroundBoutonAction.color
    property bool selectionnable: true
    //property alias  lancerAnimationCouleur: animationCouleurBoutonAction.running

    width: parent.width * 0.2
    height: parent.height * 0.2
    font.pointSize: Math.max(height * 0.4, 12)
    font.bold: true
    clip: true

    // TODO : forcer couleur noire du text
    /*
    Rectangle {
        id: rectangleEstGenie
        anchors.fill: parent
        radius: height/2
        color: "black"
        opacity: 0.5
        visible: !racineBoutonAction.selectionnable
    }*/
    opacity: selectionnable ? 1 : 0.2

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
