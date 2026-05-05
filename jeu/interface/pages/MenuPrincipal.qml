import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia

import "../composantsMenuPrincipal"

Item {
    id: racineMenuPrincipal

    signal boutonJouerClique()
    signal boutonParametresClique()

    Text {
        id: nomJeu
        text: "HEX WARS"
        color: racine.couleurTexte
        font.pointSize: Math.max(10, parent.height/12)
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ColumnLayout {
        id: layoutBoutons
        spacing: 10
        anchors.centerIn: parent

        BoutonMenuPrincipal {
           id: boutonJouer
           textBouton: qsTr("JOUER") + langageManager.chaineVide
           Layout.preferredWidth: racineMenuPrincipal.width/4
           Layout.preferredHeight: racineMenuPrincipal.height/20

           onClique : racineMenuPrincipal.boutonJouerClique()
       }

       BoutonMenuPrincipal {
           id: boutonParametres
           textBouton: qsTr("PARAMETRES") + langageManager.chaineVide
           Layout.preferredWidth: racineMenuPrincipal.width/4
           Layout.preferredHeight: racineMenuPrincipal.height/20

           onClique: racineMenuPrincipal.boutonParametresClique()
       }

       BoutonMenuPrincipal {
           id: boutonQuitter
           textBouton: qsTr("QUITTER") + langageManager.chaineVide
           Layout.preferredWidth: racineMenuPrincipal.width/4
           Layout.preferredHeight: racineMenuPrincipal.height/20

           onClique: Qt.quit()
       }
    }

}
