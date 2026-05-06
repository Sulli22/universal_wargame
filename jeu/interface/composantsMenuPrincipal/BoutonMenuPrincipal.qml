import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Button {
    id: racineBoutonMenuPrincipal

    Layout.alignment: Qt.AlignHCenter

    // Modifie la couleur du texte
    palette.buttonText: racine.couleurTexte

    background: Rectangle {
        color: parent.hovered ? "#d6d6d6" : "#2C3E50"
        border.color: "#c5b358"
        border.width: 2

    }

    // Le calcul vient du fait que la taille d'un bouton fait racineMenuPrincipal.height/20 de haut
    font.pointSize: Math.max(10,(racineMenuPrincipal.height/20)*0.4)
    font.bold: true
}


