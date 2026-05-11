#pragma once

#include "modele/modele.hh"
#include <QObject>

class ModelePourQML : public QObject {
    Q_OBJECT

public:
    explicit ModelePourQML(QObject *parent = Q_NULLPTR);

    Q_INVOKABLE void setModele(stat idGuerre);
    Q_INVOKABLE void changerJoueur();
    Q_INVOKABLE QString getStatsUniteSelectionee() const;
    Q_INVOKABLE void annulerSelections();
    Q_INVOKABLE bool indiceActionValide(indiceAction indAction) const;
    Q_INVOKABLE void choixAction(indiceAction indAction);
    Q_INVOKABLE void effectuerAction();
    Q_INVOKABLE QString getFactionAttaquante() const;
    Q_INVOKABLE bool actionValidable() const;
    Q_INVOKABLE bool actionAnnulable() const;
    Q_INVOKABLE bool indiceConstructionValide(indiceConstruction indConstruction) const;
    Q_INVOKABLE void choixConstruction(indiceConstruction indConstruction);
    Q_INVOKABLE bool partieFinie() const;
    Q_INVOKABLE QString getFactionVictorieuse() const;
    Q_INVOKABLE QString getPourcentageDefaite() const;

    bool positionValidePlateau(const Position &pos) const;
    std::size_t getLargeurPlateau() const;
    std::size_t getHauteurPlateau() const;
    Case *accesCasePlateau(const Position &pos) const;

    std::vector<Case *> getCasesConcernees() const;
    void selectionnerCase(const Position &pos);
    Case *getCaseSelectionnee() const;
    Unite *getUniteSelectionee() const;
    Case *getCaseCible() const;
    bool cheminExiste() const;
    std::vector<Case *> getChemin() const;

private:
    std::unique_ptr<Modele> _modele;
};
