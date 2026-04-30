import QtQuick
import QtQuick.Layouts

import "../composantsChoixGuerre"

Item {
    id: racineChoixGuerre

    signal boutonGuerre0Clique
    signal boutonGuerre1Clique
    signal boutonGuerre2Clique

    ColumnLayout {
        id: layoutGeneral
        anchors.fill: parent

        Text {
            id: labelChoixGuerre
            text: qsTr("Choix de la guerre") + languageManager.chaineVide
            color: racine.couleurTexte
            font.italic: true
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: Math.max(20, racineChoixGuerre.height/20)
        }

        Item {
            Layout.fillHeight: true
        }

        ColumnLayout {
            id: layoutBoutonsChoix

            BoutonChoixGuerre {
                id: boutonGuerre1
                Layout.preferredHeight: Math.max(10, racineChoixGuerre.height/4)
                sourceImage: "qrc:/waterloo"
                nomGuerre: "Guerre 0"
                onClique : racineChoixGuerre.boutonGuerre0Clique()
            }

            BoutonChoixGuerre {
                id: boutonGuerre2
                Layout.preferredHeight: Math.max(10, racineChoixGuerre.height/4)
                sourceImage: "qrc:/waterloo"
                nomGuerre: "Guerre 1"
                onClique : racineChoixGuerre.boutonGuerre1Clique()
            }

            BoutonChoixGuerre {
                id: boutonGuerre3
                Layout.preferredHeight: Math.max(10, racineChoixGuerre.height/4)
                sourceImage: "qrc:/waterloo"
                nomGuerre: "Guerre 2"
                onClique : racineChoixGuerre.boutonGuerre2Clique()
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
