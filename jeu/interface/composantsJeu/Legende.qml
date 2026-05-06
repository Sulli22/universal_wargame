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
        }

        LigneLegende {
           id: bombardier
           nomUnite: qsTr("Bombardier")
        }

        LigneLegende {
            id: charAssaut
            nomUnite: qsTr("Char d'assaut")
        }

        LigneLegende {
            id: chasseur
            nomUnite: qsTr("Chasseur")
        }

        LigneLegende {
            id: fregate
            nomUnite: qsTr("Fregate")
        }

        LigneLegende {
            id: genie
            nomUnite: qsTr("Génie")
        }

        LigneLegende {
           id: infanterie
           nomUnite: qsTr("Infanterie")
        }

        LigneLegende {
            id: sousMarin
            nomUnite: qsTr("Sous marin")
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

