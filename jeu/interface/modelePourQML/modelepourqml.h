#pragma once

#include "modele/modele.hh"
#include <QObject>

class ModelePourQML : public QObject {
    Q_OBJECT

public:
    explicit ModelePourQML(QObject *parent = Q_NULLPTR);

    Q_SLOT void setModele(usint idGuerre);
    const Carte &getPlateau() const;

private:
    std::unique_ptr<Modele> _modele;
};
