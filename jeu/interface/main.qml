import QtQuick
import QtQuick.Window
import QtMultimedia

import "divers"

Window {
    id: racine
    readonly property string couleurTexte: "#f5f5dc"

    property real volumeMusique: 0.25
    property real volumeBruitages: 0.5
    property bool desactiverVolumeBruitages: false
    property bool desactiverVolumeMusique: false
    property int indiceLangue: 0

    visibility: Window.FullScreen
    width: Screen.width
    height: Screen.height
    visible: true
    title: "HEX WARS"

    MediaPlayer {
        id: sonMusique
        source: musiqueUrl
        loops: MediaPlayer.Infinite

        audioOutput: AudioOutput {
            volume: racine.desactiverVolumeMusique ? 0 : racine.volumeMusique
        }

        Component.onCompleted: sonMusique.play()
    }

    Component {
            id: composantSonBouton
            MediaPlayer {
                source: "qrc:/clic"
                audioOutput: AudioOutput {
                   volume: racine.desactiverVolumeBruitages ? 0 : racine.volumeBruitages
                }
            }
        }

    Background {
        anchors.fill: parent
    }

    Loader {
       id: pageLoader
       anchors.fill: parent
       source: "pages/Credits.qml"

       Connections {
            target: pageLoader.item
            enabled: pageLoader.status === Loader.Ready
            ignoreUnknownSignals: true

            function onAnimationTerminee() {
                pageLoader.source = "pages/MenuPrincipal.qml"
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
                pageLoader.source = "pages/MenuPrincipal.qml"
            }

            function onBoutonGuerreClique(indice) {
                lancerBruitBouton()
                modeleQML.setModele(indice);
                pageLoader.source = "pages/PageJeu.qml"
            }

            function onRetourMenuPrincipal(fenetre) {
                if (fenetre)
                    Qt.quit()
                else
                    pageLoader.source = "pages/MenuPrincipal.qml"
            }

        }
    }

    function lancerBruitBouton() {
        let son = composantSonBouton.createObject(racine)
        son.play()
        son.playbackStateChanged.connect(function() {
            if (son.playbackState === MediaPlayer.StoppedState)
                son.destroy(500)
           })
    }
}
