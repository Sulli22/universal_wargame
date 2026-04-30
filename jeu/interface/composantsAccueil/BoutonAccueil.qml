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

        // Modifie la couleur du texte
        palette.buttonText: racine.couleurTexte

        background: Rectangle {
            color: parent.hovered ? "#d6d6d6" : "#2C3E50"
            border.color: "#c5b358"
            border.width: 2
        }
        width:racineBoutonAccueil.width
        height: racineBoutonAccueil.height

        font.pointSize: Math.max(10,racineBoutonAccueil.height*0.4)
        font.bold: true
        /*
        clip: true
        anchors.right: parent.right
        PropertyAnimation { id: animation;
                              target: boutonAccueil;
                              property: "width";
                              from:0;
                              to: racineBoutonAccueil.width
                              duration: 1000;
                              easing.type: Easing.OutBack

        }


        Component.onCompleted: {
            animation.running = true
        }
        */

        onClicked: racineBoutonAccueil.clique()
    }


}
