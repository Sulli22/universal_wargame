import QtQuick
import QtQuick.Window
import QtMultimedia

import "divers"

Window {
    id: racine
    readonly property string couleurTexte: "#f5f5dc"

    property real volumeMusique: 0.25
    property real volumeBouton: 0.5
    property bool desactiverVolumeBouton: false
    property bool desactiverVolumeMusique: false
    property int indiceLangue: 0

    signal onAnimationTerminee()
    signal onBoutonParametreClique()

    visibility: Window.FullScreen
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Wargame")

    MediaPlayer {
        id: sonMusique
        source: "file://" + applicationDirPath + "/warzone.mp3"
        loops: MediaPlayer.Infinite
        audioOutput: AudioOutput {
            volume: racine.desactiverVolumeMusique ? 0 : racine.volumeMusique
        }

        Component.onCompleted: {
            sonMusique.play()
        }
    }

    Component {
        id: composantSon
        MediaPlayer {
            source: "qrc:/bouton.wav"
            audioOutput: AudioOutput {
                volume: racine.desactiverVolumeBouton ? 0 : racine.volumeBouton
            }
        }
    }


    Background {
        anchors.fill: parent
    }

    Loader {
       id: pageLoader
       anchors.fill: parent
       source: "pages/PreAccueil.qml"

       Connections {
            target: pageLoader.item
            enabled: pageLoader.status === Loader.Ready
            ignoreUnknownSignals: true

            function onAnimationTerminee() {
                pageLoader.source = "pages/Accueil.qml"
            }

            function onBoutonJouerClique() {
                lancerBruitBouton();

                pageLoader.source = "pages/PageChoixGuerre.qml"
            }

            function onBoutonParametresClique() {
                lancerBruitBouton()
                pageLoader.source = "pages/Parametres.qml"
            }


            function onBoutonRetourClique() {
                lancerBruitBouton()
                pageLoader.source = "pages/Accueil.qml"
            }

            function onBoutonGuerre1Clique() {
                lancerBruitBouton()
                pageLoader.source = "pages/PageJeu.qml"
            }

            function onBoutonGuerre2Clique() {
                lancerBruitBouton()
                pageLoader.source = "pages/PageJeu.qml"
            }

            function onBoutonGuerre3Clique() {
                lancerBruitBouton()
                pageLoader.source = "pages/PageJeu.qml"
            }
       }
   }

function lancerBruitBouton() {
    let son = composantSon.createObject(racine)
    son.play()
    son.playbackStateChanged.connect(function() {
        if (son.playbackState === MediaPlayer.StoppedState) {
            son.destroy(500)
           }
       })
}

}
