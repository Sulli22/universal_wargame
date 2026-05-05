import QtQuick 2.15
import QtQuick.Controls

Button {
    id: racineBoutonAction

    property alias equipe: backgroundBoutonAction.color

    width: parent.width * 0.2
    height: parent.height * 0.2
    font.pointSize: Math.max(height * 0.4, 12)
    font.bold: true
    clip: true

    background: Rectangle {
        id: backgroundBoutonAction
        radius: height/2
    }

    PropertyAnimation {
        id: animation;
        target: racineBoutonAction;
        property: "width";
        from:0;
        to: racineBoutonAction.width
        duration: 1000;
        easing.type: Easing.OutBack
    }

    Component.onCompleted: {
        animation.running = true
    }
}
