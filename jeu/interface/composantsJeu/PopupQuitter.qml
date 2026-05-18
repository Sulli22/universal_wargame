import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

PopupGeneral {
    id: racinePopupQuitter

    property bool fenetre: true
    signal retourMenuPrincipalPopup()
    contentItem: Item {
        ColumnLayout {
            id: layoutPopup
            anchors.centerIn: parent

            Label {
                id: labelQuitter
                text: racinePopupQuitter.fenetre ?
                          qsTr("Voulez vous vraiment quitter le jeu ?") + langageManager.chaineVide :
                          qsTr("Voulez vous vraiment quitter la partie ?") + langageManager.chaineVide
                color: "black"
                font.pointSize: 20
                font.bold: true
            }

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                Button {
                    id: boutonQuitter
                    text: qsTr("Quitter") + langageManager.chaineVide
                    palette.buttonText: "black"
                    Layout.preferredWidth: racinePopupQuitter.width*0.2
                    font.bold: true
                    background: Rectangle {
                        radius: height/2
                        gradient: Gradient {
                            orientation: Gradient.Horizontal
                            GradientStop {position: 0.0; color:"red"}
                            GradientStop {position: 0.5; color: "#de7307"}
                            GradientStop {position: 1.0; color: "red"}
                        }
                    }
                    onClicked: racinePopupQuitter.retourMenuPrincipalPopup()
                }

                Button {
                    id: boutonAnnuler
                    text: qsTr("Annuler") + langageManager.chaineVide
                    palette.buttonText: "black"
                    Layout.preferredWidth: racinePopupQuitter.width*0.2
                    font.bold: true
                    onClicked: function fermerPopupQuitter(){
                        close()
                        rectangleOpacite.visible = false
                    }
                    background: Rectangle {
                        radius: height/2
                    }
                }

                Item {
                    Layout.fillHeight: true
                }
            }
        }
    }


}
