import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia

PopupGeneral {
    id: racinePopupVictoire

    contentItem: Item {
        MediaPlayer {
            id: sonVictoire
            source: "qrc:/victoire"
            audioOutput: AudioOutput {volume: racine.volumeBouton}
        }

        ColumnLayout {
            id: layoutVictoire
            anchors.fill: parent
            Text {
                id: texteVictoire

                text: "VICTOIRE DE : "
                font.pointSize: Math.max(25,layoutVictoire.width * 0.075)
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
            }

            Rectangle {
                Layout.preferredWidth: layoutVictoire.width * 0.5
                Layout.preferredHeight: layoutVictoire.height * 0.4
                border.color: racine.couleurTexte
                color: modeleQML.getFactionVictorieuse()
                Layout.alignment: Qt.AlignHCenter
            }

            Button {
                id: boutonRetourMenuPrincipal
                text: qsTr("Retour au menu principal") + langageManager.chaineVide
                Layout.alignment: Qt.AlignHCenter
                font.pointSize: Math.max(15, boutonRetourMenuPrincipal.Layout.preferredHeight*0.4)
                onClicked: racineJeu.retourMenuPrincipal(false)
            }

        }
    }
    onOpened: sonVictoire.play()
}
