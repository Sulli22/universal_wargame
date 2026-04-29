import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia

import "../composantsAccueil"

Item {
    id: racineAccueil

    signal boutonJouerClique()
    signal boutonParametresClique()

    Text {
        id: nomJeu
        text: "HEX OF STEEL"
        color: racine.couleurTexte
        font.pointSize: Math.max(10, parent.height/12)
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter

    }

    ColumnLayout {
        id: layoutBoutons
        spacing: 10
        anchors.centerIn: parent

        BoutonAccueil {
           id: boutonJouer
           textBouton: qsTr("JOUER") + languageManager.chaineVide
           Layout.preferredWidth: racineAccueil.width/4
           Layout.preferredHeight: racineAccueil.height/20

           onClique : racineAccueil.boutonJouerClique()

       }

       BoutonAccueil {
           id: boutonParametres
           textBouton: qsTr("PARAMETRES") + languageManager.chaineVide
           Layout.preferredWidth: racineAccueil.width/4
           Layout.preferredHeight: racineAccueil.height/20

           onClique: racineAccueil.boutonParametresClique()

       }

       BoutonAccueil {
           id: boutonQuitter
           textBouton: qsTr("QUITTER") + languageManager.chaineVide
           Layout.preferredWidth: racineAccueil.width/4
           Layout.preferredHeight: racineAccueil.height/20

           onClique: Qt.quit()
       }
    }

}
