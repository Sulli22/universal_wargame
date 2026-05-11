import QtQuick 2.15
import QtQuick.Controls

Popup {
    id: racinePopupGeneral

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
}
