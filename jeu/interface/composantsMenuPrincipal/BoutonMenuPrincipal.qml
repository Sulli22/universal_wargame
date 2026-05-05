import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: racineBoutonAccueil

    signal clique
    property alias textBouton: boutonAccueil.text

    Layout.alignment: Qt.AlignHCenter

    Button {
        id: boutonAccueil
        width:racineBoutonAccueil.width
        height: racineBoutonAccueil.height
        font.pointSize: Math.max(10,racineBoutonAccueil.height*0.4)
        font.bold: true

        // Modifie la couleur du texte
        palette.buttonText: racine.couleurTexte

        background: Rectangle {
            color: parent.hovered ? "#d6d6d6" : "#2C3E50"
            border.color: "#c5b358"
            border.width: 2
        }

        onClicked: racineBoutonAccueil.clique()
    }


}
