import QtQuick 2.15
import QtQuick.Layouts

RowLayout {
    id: racineLigneLegende
    property alias nom: nom.text
    property alias image: image.source

    Layout.preferredWidth: racinePopupLegende.width/3
    Layout.preferredHeight: racinePopupLegende.height/10
    Layout.alignment: Qt.AlignHCenter
    Image {
        id: image
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        Layout.preferredWidth: 150
        Layout.preferredHeight: 85
        fillMode: Image.PreserveAspectFit
    }
    Text {
        id: nom
        color: racine.couleurTexte
        font.pointSize: Math.max(racineLigneLegende.Layout.preferredHeight * 0.4, 15)
        Layout.fillWidth: true
        horizontalAlignment: Text.AlignHCenter
        Layout.alignment: Qt.AlignHCenter

    }

}
