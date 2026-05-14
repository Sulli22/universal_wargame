import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia

PopupGeneral {
    id: racinePopupVictoire


    function lancerBruitVictoire() {
        let son = composantSonVictoire.createObject(racinePopupVictoire)
        son.play()
        son.playbackStateChanged.connect(function() {
            if (son.playbackState === MediaPlayer.StoppedState) {
                son.destroy(500)
               }
           })
    }

    contentItem: Item {

        Component {
               id: composantSonVictoire
               MediaPlayer {
                   source: "qrc:/victoire"
                   audioOutput: AudioOutput {
                       volume: racine.desactiverVolumeBruitages ? 0 : racine.volumeBruitages
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

                background: Rectangle {
                    radius: height/2
                    border.color: "black"
                }
                onClicked: racineJeu.retourMenuPrincipal(false)
            }

        }
    }

    onOpened: function ouvrirPopupVictoire(){
        rectFaction.color = modeleQML.getFactionVictorieuse()
        lancerBruitVictoire()
    }


}
