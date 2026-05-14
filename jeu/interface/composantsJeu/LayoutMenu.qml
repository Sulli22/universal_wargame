import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    id: layoutMenu



    function rafraichirBoutonsActions() {
        deplacer.enabled = modeleQML.indiceActionValide(0);
        attaquer.enabled = modeleQML.indiceActionValide(1);
        construire.enabled = modeleQML.indiceActionValide(2);
    }

    function rafraichirBoutonsConstruction() {
        depotMunitions.enabled = modeleQML.indiceConstructionValide(0);
        depotProvisions.enabled = modeleQML.indiceConstructionValide(1);
        infirmerie.enabled = modeleQML.indiceConstructionValide(2);
        pont.enabled = modeleQML.indiceConstructionValide(3);
    }

    function rafraichierBoutons() {
        rafraichirStats()
        rafraichirBoutonsActions()
        rafraichirBoutonsConstruction()
        plateau.update()
    }

    function gererCliqueMouseArea(x, y) {
        plateau.gererClic(x, y)
        stats.text = modeleQML.getStatsUniteSelectionee()
        rafraichirBoutonsActions()
        rafraichirBoutonsConstruction()
        boutonValider.enabled = modeleQML.actionValidable()
        boutonAnnuler.enabled = modeleQML.actionAnnulable()
    }

    function choixConstruction(ind) {
        modeleQML.choixConstruction(ind)
        boutonValider.enabled = modeleQML.actionValidable()
    }

    function choixAction(ind) {
        racine.lancerBruitBouton()
        modeleQML.choixAction(ind);
        plateau.update();
    }

    function rafraichirStats() {
        stats.text = "Pas d'unite"
    }

    anchors.fill: parent
    spacing: 3

    Label {
        id: labelJoueur
        text: qsTr("Joueur : ") + langageManager.chaineVide
        font.pointSize: 18
        font.bold: true
        color: racine.couleurTexte
        Layout.fillWidth: true
        horizontalAlignment: Text.AlignHCenter
    }

    Rectangle {
        id: couleurJoueur
        color: racineJeu.equipeAttaquante
        Layout.preferredWidth: layoutMenu.width * 0.5
        Layout.preferredHeight: layoutMenu.height * 0.05
        Layout.alignment: Qt.AlignHCenter
        border.color: racine.couleurTexte

        Behavior on color {
            ColorAnimation {
                duration: 1000
            }
        }
    }

    Rectangle {
        color: "black"
        Layout.fillWidth: true
        Layout.preferredHeight: 5
    }

    ColumnLayout {
        id: layoutStat
        spacing: 0

        Label {
           id: labelStats
           text: qsTr("Stats Unité") + langageManager.chaineVide
           color: racine.couleurTexte
           Layout.fillWidth: true
           horizontalAlignment: Text.AlignHCenter
           font.pointSize: 18
           font.bold: true
        }

        Text {
           id: stats
           text: qsTr("Pas d'unité") + langageManager.chaineVide
           color: racine.couleurTexte
           Layout.fillWidth: true
           horizontalAlignment: Text.AlignHCenter
           font.pointSize: 18
        }
    }

    Rectangle {
        color: "black"
        Layout.fillWidth: true
        Layout.preferredHeight: 5
    }

    Label {
        id: labelConstructions
        text: qsTr("Constructions") + langageManager.chaineVide
        color: racine.couleurTexte
        Layout.alignment: Qt.AlignHCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 18
        font.bold: true
    }

    ColumnLayout {
        id: layoutConstructions
        spacing: 8

        BoutonMenu {
            id: depotMunitions
            text: qsTr("Munitions") + langageManager.chaineVide
            equipe: racineJeu.equipeAttaquante
            enabled: false

            onClicked: {
                choixConstruction(0)
            }
        }

        BoutonMenu {
            id: depotProvisions
            text: qsTr("Provisions") + langageManager.chaineVide
            equipe: racineJeu.equipeAttaquante
            enabled: false

            onClicked: {
                choixConstruction(1)
            }
        }

        BoutonMenu {
            id: infirmerie
            text: qsTr("Infirmerie") + langageManager.chaineVide
            equipe: racineJeu.equipeAttaquante
            enabled: false

            onClicked: {
                choixConstruction(2)
            }
        }

        BoutonMenu {
            id: pont
            text: qsTr("Pont") + langageManager.chaineVide
            equipe: racineJeu.equipeAttaquante
            enabled: false

            onClicked: {
                choixConstruction(3)
            }
        }
    }

    Rectangle {
        color: "black"
        Layout.fillWidth: true
        Layout.preferredHeight: 5
    }

    ColumnLayout {
        id: layoutActions
        spacing: 8

        BoutonMenu {
            id: deplacer
            text: qsTr("Déplacer") + langageManager.chaineVide
            equipe: racineJeu.equipeAttaquante
            enabled: false

            onClicked: {
                choixAction(0)
            }
        }

        BoutonMenu {
            id: attaquer
            text: qsTr("Attaquer") + langageManager.chaineVide
            equipe: racineJeu.equipeAttaquante
            enabled: false

            onClicked: {
                choixAction(1)
            }
        }

        BoutonMenu {
            id: construire
            text: qsTr("Construire") + langageManager.chaineVide
            equipe: racineJeu.equipeAttaquante
            enabled: false

            onClicked: {
                choixAction(2)
            }
        }

        RowLayout {
            id: layoutValidation
            Layout.alignment: Qt.AlignBottom
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.maximumHeight: layoutMenu.height * 0.05
            Layout.rightMargin: 5
            Layout.leftMargin: 5

            BoutonChoix {
                id: boutonAnnuler
                text: "✗"
                couleurExtremiteGradient: "red"
                couleurCentreGradient: "#de7307"
                enabled: false

                onClicked: function annulation(){
                    modeleQML.annulerSelections()
                    enabled = false
                    stats.text = "Pas d'unite"
                    rafraichierBoutons()
                }
            }

            BoutonChoix {
                id: boutonValider
                text: "✔"
                couleurExtremiteGradient: "green"
                couleurCentreGradient: "#95ff80"
                enabled: false

                onClicked: function validation(){
                    let estActionAttaquante = modeleQML.estActionAttaque()
                    modeleQML.effectuerAction()

                    if (modeleQML.partieFinie())
                        popupVictoire.open()
                    else if (estActionAttaquante)
                        lancerBruitAttaque()

                    enabled = false
                    boutonAnnuler.enabled = false
                    racineJeu.equipeAttaquante = modeleQML.getFactionAttaquante()
                    rafraichierBoutons()
                }
            }
        }
    }

    Rectangle {
        color: "black"
        Layout.fillWidth: true
        Layout.preferredHeight: 5
    }

    BoutonMenu {
        id: changerJoueur
        text: qsTr("Joueur suivant")
        Layout.fillWidth: true
        Layout.preferredHeight: layoutMenu.height*0.05
        Layout.bottomMargin: 10
        Layout.rightMargin: 5
        Layout.leftMargin: 5

        onClicked: function changementJoueur(){
            racine.lancerBruitBouton()
            modeleQML.changerJoueur()
            racineJeu.equipeAttaquante = modeleQML.getFactionAttaquante()
            rafraichierBoutons()
        }
    }
}
