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
        id: layoutVolume
        anchors.fill: parent
        anchors.horizontalCenter:parent.horizontalCenter
        spacing: 1

        Text {
            id: labelVolume
            text: "VOLUME"
            color: racine.couleurTexte
            font.bold: true
            font.pointSize: Math.max(racine.height/40, 10)
            Layout.alignment: Qt.AlignHCenter

        }

        ColumnLayout {
            id: partieVolume
            spacing: 3
            Layout.fillWidth: true
            Layout.margins: 8



            SliderVolume {
                id: sliderVolume
                Layout.fillHeight: true
                Layout.fillWidth: true
            }




            RowLayout {
                spacing: 100

                CheckBoxVolume {
                    id: checkBoxDesactiveMusique
                    text: qsTr("Désactiver musique") + languageManager.chaineVide
                    checked: racine.desactiverVolumeMusique
                    onToggled: {
                        racine.desactiverVolumeMusique = checked
                    }
                }



                CheckBoxVolume {
                    id: checkBoxDesactiveBruit
                    text: qsTr("Désactiver bruitage") + languageManager.chaineVide
                    checked: racine.desactiverVolumeBouton

                    onToggled: {
                        racine.desactiverVolumeBouton = checked
                    }
                }

                Layout.alignment: Qt.AlignHCenter
            }


            Item {
                Layout.fillHeight: true
            }
        }


    }
}
