import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../composantsParametres"
import "../divers"
Item {
    id: racineParametres

    signal boutonRetourClique()

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.fill: parent

    Background {
        anchors.fill: parent
    }

    ColumnLayout {
        id: layoutParametres
        anchors.horizontalCenter: parent.horizontalCenter
        width: Math.max(100, racineParametres.width/2)
        height: racineParametres.height
        Text {
            id: labelParametres
            text: qsTr("PARAMETRES") + languageManager.chaineVide
            color: racine.couleurTexte
            font.pointSize: Math.max(racineParametres.height/20, 20)
            font.italic: true
            Layout.alignment: Qt.AlignHCenter
        }


        ParametresVolume {
            id: partieVolume
            Layout.fillWidth: true
            Layout.preferredHeight: layoutParametres.height*0.2

        }

        ParametresLangue {
            id: partieLangue
            Layout.fillWidth: true
            Layout.preferredHeight: layoutParametres.height*0.1
        }

        Item {
            Layout.fillHeight: true
        }

    }

    Button {
        id: boutonRetour
        text: qsTr("Retour") + languageManager.chaineVide
        width: parent.width*0.05
        height: parent.height*0.025
        font.pointSize: Math.max(1,height*0.4)
        x: parent.width*0.95
        y: parent.height*0.975
        onClicked: racineParametres.boutonRetourClique()
    }
}


