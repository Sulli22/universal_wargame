import QtQuick
import QtQuick.Layouts

import "../composantsChoixGuerre"

Item {
    id: racineChoixGuerre

    signal boutonGuerreClique(int indice)

    ColumnLayout {
        id: layoutGeneral
        anchors.fill: parent

        Text {
            id: labelChoixGuerre
            text: qsTr("Choix de la difficulté") + langageManager.chaineVide
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
                id: boutonNiveau1
                Layout.preferredHeight: Math.max(10, racineChoixGuerre.height/4)
                sourceImage: "qrc:/img/facile"
                nomGuerre: qsTr("Facile") + langageManager.chaineVide
                onClique : racineChoixGuerre.boutonGuerreClique(0)
            }

            BoutonChoixGuerre {
                id: boutonNiveau2
                Layout.preferredHeight: Math.max(10, racineChoixGuerre.height/4)
                sourceImage: "qrc:/img/moyen"
                nomGuerre: qsTr("Moyen") + langageManager.chaineVide
                onClique : racineChoixGuerre.boutonGuerreClique(1)
            }

            BoutonChoixGuerre {
                id: boutonNiveau3
                Layout.preferredHeight: Math.max(10, racineChoixGuerre.height/4)
                sourceImage: "qrc:/img/difficile"
                nomGuerre: qsTr("Difficile") + langageManager.chaineVide
                onClique : racineChoixGuerre.boutonGuerreClique(2)
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
