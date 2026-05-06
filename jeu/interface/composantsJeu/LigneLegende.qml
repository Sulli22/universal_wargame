import QtQuick 2.15
import QtQuick.Layouts

RowLayout {
    id: racineLigneLegende
    property alias nomUnite: nomUnite.text
    Layout.fillWidth: true
    Layout.preferredHeight: racineJeu.height/10
    Layout.alignment: Qt.AlignHCenter

    Text {
        id: nomUnite
        color: racine.couleurTexte
        font.pointSize: Math.max(racineLigneLegende.height * 0.4, 15)
    }
}
