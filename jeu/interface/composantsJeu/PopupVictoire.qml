import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia

PopupGeneral {
    id: racinePopupVictoire

    contentItem: Item {

        Component {
               id: composantSonVictoire
               MediaPlayer {
                   source: "qrc:/victoire"
                   audioOutput: AudioOutput {
                       volume: racine.desactiverVolumeBouton ? 0 : racine.volumeBouton
                   }
               }
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
                id: rectFaction
                Layout.preferredWidth: layoutVictoire.width * 0.5
                Layout.preferredHeight: layoutVictoire.height * 0.4
                border.color: racine.couleurTexte
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

    onOpened: {
        rectFaction.color = modeleQML.getFactionVictorieuse()
        lancerBruitVictoire()
    }

    function lancerBruitVictoire() {
        let son = composantSonVictoire.createObject(racinePopupVictoire)
        son.play()
        son.playbackStateChanged.connect(function() {
            if (son.playbackState === MediaPlayer.StoppedState) {
                son.destroy(500)
               }
           })
    }

}
