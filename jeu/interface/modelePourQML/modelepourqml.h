#pragma once

#include "modele/modele.hh"
#include <QObject>

class ModelePourQML : public QObject {
    Q_OBJECT

public:
    explicit ModelePourQML(QObject *parent = Q_NULLPTR);

    Q_INVOKABLE void setModele(uint16_t idGuerre);
    Q_INVOKABLE void changementJoueur();
    Q_INVOKABLE QString getStatsUniteSelectionee() const;
    Q_INVOKABLE void annulerSelections();
    Q_INVOKABLE uint16_t getNbActionsPossibles() const;
    Q_INVOKABLE void choixAction(uint16_t indAction);
    Q_INVOKABLE void effectuerAction();
    Q_INVOKABLE QString getFactionAttaquante() const;

    bool positionValidePlateau(const Position &pos) const;
    std::size_t getLargeurPlateau() const;
    std::size_t getHauteurPlateau() const;
    Case *accesCasePlateau(const Position &pos) const;

    void selectionnerCase(const Position &pos);
    std::vector<Case *> getCasesConcernees() const;
    bool estConcernee(const Position &pos) const;
    Case *getCaseSelectionnee() const;
    Unite *getUniteSelectionee() const;
    Case *getCaseCible() const;

private:
    std::unique_ptr<Modele> _modele;
};
