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
        width: racineMenuPrincipal.width/4
        height: 3*racineMenuPrincipal.height/20 + (spacing * 2)

        BoutonMenuPrincipal {
           id: boutonJouer

           text: qsTr("JOUER") + langageManager.chaineVide
           Layout.fillWidth: true
           Layout.fillHeight: true

           onClicked : racineMenuPrincipal.boutonJouerClique()
       }

       BoutonMenuPrincipal {
           id: boutonParametres

           text: qsTr("PARAMETRES") + langageManager.chaineVide
           Layout.fillWidth: true
           Layout.fillHeight: true

           onClicked: racineMenuPrincipal.boutonParametresClique()
       }

       BoutonMenuPrincipal {
           id: boutonQuitter

           text: qsTr("QUITTER") + langageManager.chaineVide
           Layout.fillWidth: true
           Layout.fillHeight: true

           onClicked: Qt.quit()
       }
    }

}
