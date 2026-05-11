import QtQuick 2.15
import QtQuick.Layouts

RowLayout {
    id: racineLigneLegende
    property alias nomUnite: nomUnite.text
    property alias imageUnite: imageUnite.source

    Layout.preferredWidth: racinePopupLegende.width/3
    Layout.preferredHeight: racinePopupLegende.height/10
    Layout.alignment: Qt.AlignHCenter
    Image {
        id: imageUnite
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        Layout.preferredWidth: 150
        Layout.preferredHeight: 85
    }
    Text {
        id: nomUnite
        color: racine.couleurTexte
        font.pointSize: Math.max(racineLigneLegende.Layout.preferredHeight * 0.4, 15)
        Layout.fillWidth: true
        horizontalAlignment: Text.AlignHCenter
        Layout.alignment: Qt.AlignHCenter

    }

}
