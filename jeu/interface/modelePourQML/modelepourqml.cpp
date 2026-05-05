#include "modelepourqml.h"

ModelePourQML::ModelePourQML(QObject *parent):
    QObject(parent)
{}

void ModelePourQML::setModele(uint16_t idGuerre)
{
    _modele = std::make_unique<Modele>(idGuerre);
}

const Carte &ModelePourQML::getPlateau() const
{
    return _modele->getPlateau();
}
