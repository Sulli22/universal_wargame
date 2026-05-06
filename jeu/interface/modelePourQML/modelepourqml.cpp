#include "modelepourqml.h"

ModelePourQML::ModelePourQML(QObject *parent):
    QObject(parent)
{}

void ModelePourQML::setModele(uint16_t idGuerre)
{
    _modele = std::make_unique<Modele>(idGuerre);
}

void ModelePourQML::selectionnerCase(const Position &pos)
{
    _modele->selectionnerCase(pos);
}

std::vector<Case *> ModelePourQML::getCasesConcernees() const
{
    return _modele->getCasesConcernees();
}

Case *ModelePourQML::getCaseSelectionnee() const
{
    return _modele->getCaseSelectionnee();
}

bool ModelePourQML::positionValidePlateau(const Position &pos) const
{
    return _modele->positionValidePlateau(pos);
}

std::size_t ModelePourQML::getLargeurPlateau() const
{
    return _modele->getLargeurPlateau();
}

std::size_t ModelePourQML::getHauteurPlateau() const
{
    return _modele->getHauteurPlateau();
}

Case *ModelePourQML::accesCasePlateau(const Position &pos) const
{
    return _modele->accesCasePlateau(pos);
}

void ModelePourQML::changementJoueur()
{
    _modele->changementJoueur();
}

QString ModelePourQML::getStatsUniteSelectionee() const
{
    //_modele.getUniteSelectionee()
}
