import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../divers"
Popup {
    id: racinePopupLegende
    width: racineJeu.width
    height: racineJeu.height
    background: Background {}

    contentItem: Item {
        RowLayout {
            anchors.centerIn: parent
            spacing: 100
            ColumnLayout {
                id: layoutUnites
                spacing: 20
                Layout.fillHeight: true
                Layout.fillWidth: true
                LigneLegende {
                    id: artillerie
                    nom: qsTr("Artillerie") + langageManager.chaineVide
                    image: "qrc:/img/artillerie"
                }

                LigneLegende {
                   id: bombardier
                   nom: qsTr("Bombardier") + langageManager.chaineVide
                   image: "qrc:/img/bombardier"
                }

                LigneLegende {
                    id: charAssaut
                    nom: qsTr("Char d'assaut") + langageManager.chaineVide
                    image: "qrc:/img/char"
                }

                LigneLegende {
                    id: chasseur
                    nom: qsTr("Chasseur") + langageManager.chaineVide
                    image: "qrc:/img/chasseur"
                }

                LigneLegende {
                    id: fregate
                    nom: qsTr("Frégate") + langageManager.chaineVide
                    image: "qrc:/img/fregate"
                }

                LigneLegende {
                    id: genie
                    nom: qsTr("Génie") + langageManager.chaineVide
                    image: "qrc:/img/genie"
                }

                LigneLegende {
                   id: infanterie
                   nom: qsTr("Infanterie") + langageManager.chaineVide
                   image: "qrc:/img/infanterie"
                }


                LigneLegende {
                    id: sousMarin
                    nom: qsTr("Sous marin") + langageManager.chaineVide
                    image: "qrc:/img/sousmarin"
                }
            }

            ColumnLayout {
                id: layoutConstructions
                spacing: 20
                Layout.fillHeight: true
                Layout.fillWidth: true

                LigneLegende {
                    id: depotMunitions
                    nom: qsTr("Dépot munitions") + langageManager.chaineVide
                    image: "qrc:/img/munitions"
                }

                LigneLegende {
                    id: depotProvisions
                    nom: qsTr("Dépot provisions") + langageManager.chaineVide
                    image: "qrc:/img/provisions"
                }

                LigneLegende {
                    id: infirmerie
                    nom: qsTr("Infirmerie") + langageManager.chaineVide
                    image: "qrc:/img/infirmerie"
                }

                LigneLegende {
                    id: pont
                    nom: qsTr("Pont") + langageManager.chaineVide
                    image: "qrc:/img/pont"
                }
            }

        }

        Button {
            id: boutonRetour
            text: qsTr("Retour") + langageManager.chaineVide
            width: parent.width*0.05
            height: parent.height*0.025
            font.pointSize: Math.max(10,height*0.4)
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            onClicked: close()
        }

    }
}

