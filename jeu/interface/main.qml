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


    visibility: Window.FullScreen
    width: Screen.width
    height: Screen.height
    visible: true
    title: "HEX WARS"

    MediaPlayer {
        id: sonMusique
        source: applicationDirPath + "/warzone.mp3"
        loops: MediaPlayer.Infinite

        audioOutput: AudioOutput {
            volume: racine.desactiverVolumeMusique ? 0 : racine.volumeMusique
        }

        Component.onCompleted: sonMusique.play()
    }

    SoundEffect {
        id: sonBoutton
        source: "qrc:/clic"
        volume: racine.desactiverVolumeBouton ? 0 : racine.volumeBouton
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
        sonBoutton.stop()
        sonBoutton.play()
    }
}
