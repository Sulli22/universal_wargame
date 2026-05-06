#pragma once

#include "modele/modele.hh"
#include <QObject>

class ModelePourQML : public QObject {
    Q_OBJECT

public:
    explicit ModelePourQML(QObject *parent = Q_NULLPTR);

    Q_INVOKABLE void setModele(uint16_t idGuerre);
    Q_INVOKABLE void changementJoueur();

    bool positionValidePlateau(const Position &pos) const;
    std::size_t getLargeurPlateau() const;
    std::size_t getHauteurPlateau() const;
    Case *accesCasePlateau(const Position &pos) const;

    void selectionnerCase(const Position &pos);
    std::vector<Case *> getCasesConcernees() const;
    bool estConcernee(const Position &pos) const;
    Case *getCaseSelectionnee() const;

private:
    std::unique_ptr<Modele> _modele;
};
