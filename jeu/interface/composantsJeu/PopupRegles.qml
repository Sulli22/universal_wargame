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
                id: texteRegles
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

                onClicked: function fermerPopupRegles(){
                    close()
                    rectangleOpacite.visible = false
                }

                background: Rectangle {
                    radius: height/2
                    border.color: "black"
                }
            }
        }
    }

    Component.onCompleted: {
        texteRegles.text = qsTr("Vous allez jouer les deux factions lors de cette bataille.
                        \nL'objectif est de réduire une équipe à moins de ")
                        + modeleQML.getPourcentageDefaite()
                        + qsTr("% de son effectif initial d'unités.")
                        + langageManager.chaineVide
    }
}
