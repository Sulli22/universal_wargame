import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../divers"
Popup {
    width: racineJeu.width
    height: racineJeu.height
    background: Background {}
    ColumnLayout {
        id: layoutLegende
        anchors.fill: parent

        LigneLegende {
            id: artillerie
            nomUnite: qsTr("Artillerie")
            imageUnite: "qrc:/img/artillerie"
        }

        LigneLegende {
           id: bombardier
           nomUnite: qsTr("Bombardier")
           imageUnite: "qrc:/img/bombardier"
        }

        LigneLegende {
            id: charAssaut
            nomUnite: qsTr("Char d'assaut")
            imageUnite: "qrc:/img/char"
        }

        LigneLegende {
            id: chasseur
            nomUnite: qsTr("Chasseur")
            imageUnite: "qrc:/img/chasseur"
        }

        LigneLegende {
            id: fregate
            nomUnite: qsTr("Fregate")
            imageUnite: "qrc:/img/fregate"
        }

        LigneLegende {
            id: genie
            nomUnite: qsTr("Génie")
            imageUnite: "qrc:/img/genie"
        }

        LigneLegende {
           id: infanterie
           nomUnite: qsTr("Infanterie")
           imageUnite: "qrc:/img/infanterie"
        }


        LigneLegende {
            id: sousMarin
            nomUnite: qsTr("Sous marin")
            imageUnite: "qrc:/img/sousmarin"
        }
    }

    Button {
        id: boutonRetour
        text: qsTr("Retour") + langageManager.chaineVide
        width: parent.width*0.05
        height: parent.height*0.025
        font.pointSize: Math.max(1,height*0.4)
        x: parent.width*0.95
        y: parent.height*0.975
        onClicked: close()
    }
}

