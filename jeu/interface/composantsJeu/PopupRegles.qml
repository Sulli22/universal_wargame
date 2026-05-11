import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

PopupGeneral {
    id: racinePopupRegles
    spacing: 3
    contentItem: Item {
        ColumnLayout {
            id: layoutRegles
            anchors.fill: parent
            Text {
                id: textRegles
                text: qsTr("L'objectif est de réduire l'équipe adverse à moins de 5% par rapport à la taille de base") + langageManager.chaineVide
                font.bold: true
                Layout.preferredWidth: layoutRegles.width
                wrapMode: Text.WordWrap
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
            }

            Button {
                id: boutonOk
                text: "Ok"
                palette.buttonText: "black"
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth: racinePopupRegles.width*0.2
                font.bold: true
                onClicked: {
                    close()
                    rectangleOpacite.visible = false
                }
                background: Rectangle {
                    radius: height/2
                }
            }

        }
    }

}
