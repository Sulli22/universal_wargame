import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Item {
    id: racineBoutonAccueil
    signal clique
    property alias textBouton: boutonGuerre.text

    Layout.alignment: Qt.AlignHCenter


    Button {
        id: boutonGuerre

        // Modifie la couleur du texte
        palette.buttonText: racine.couleurTexte

        background: Rectangle {
            color: parent.hovered ? "#d6d6d6" : "#2C3E50"
        }
        width: racineBoutonAccueil.width
        height: racineBoutonAccueil.height

        font.pointSize: Math.max(10,racineBoutonAccueil.height*0.4)
        font.bold: true

        onClicked: racineBoutonAccueil.clique()
    }

    Rectangle {
        id: bordBouton
        anchors.fill: parent
        color: "transparent"
        border.color: "#c5b358"
        border.width: 2
    }
}
