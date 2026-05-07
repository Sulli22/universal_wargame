import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    Layout.alignment: Qt.AlignHCenter

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.color: "black"
        border.width: 2
    }

    ColumnLayout {
        id: layoutLangue
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Text {
            id: labelLangue
            text: qsTr("LANGUE") + langageManager.chaineVide
            color: racine.couleurTexte
            font.bold: true
            font.pointSize: Math.max(racineParametres.height/40, 10)
            Layout.alignment: Qt.AlignHCenter
        }

        ComboBox {
            id: selectionLangue
            Layout.fillWidth: true

            model: ListModel {
                id: cbItems
                ListElement { text:"Français"; image: "qrc:/img/france" }
                ListElement { text:"English"; image: "qrc:/img/royaumeuni" }
            }

            textRole: "text"
            currentIndex: racine.indiceLangue

            contentItem: RowLayout {
                anchors.fill: parent
                spacing: 10

                Image {
                   source: selectionLangue.model.get(selectionLangue.currentIndex).image
                   sourceSize: "24x12"
                   Layout.leftMargin: 10
                }

                Text {
                   id: nomLangueChoisie
                   color: "black"
                   text: selectionLangue.model.get(selectionLangue.currentIndex).text
                   font.bold: true
                   Layout.fillWidth: true
                }
            }

            background: Rectangle {
                id: backgroundSelectionLangue
                radius: height/2
                color: "#f5f5dc"
            }

            // Permet de personnaliser lors de l'ouverture de la liste
            delegate: ItemDelegate {
                id: control
                width: selectionLangue.width

                background: Rectangle {
                    color: control.highlighted ? "#87CEFA" : "#f5f5dc"
                }

                contentItem: RowLayout {
                    spacing: 10

                    Image {
                        source: model.image
                        sourceSize: "24x12" 
                    }

                    Text {
                        color: "black"
                        text: model.text
                        font.bold: true
                        Layout.fillWidth: true
                    }
                }

                // Permet que celui qui est sélectionné soit mis en valeur
                highlighted: selectionLangue.highlightedIndex === index
            }

            onActivated: {
                langageManager.majLangue(selectionLangue.currentIndex === 0 ? "fr" : "en")
                racine.indiceLangue = selectionLangue.currentIndex
            }
        }
    }
}
