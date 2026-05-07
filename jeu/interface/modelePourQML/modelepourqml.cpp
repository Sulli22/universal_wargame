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

Unite *ModelePourQML::getUniteSelectionee() const
{
    return _modele->getUniteSelectionee();
}

Case *ModelePourQML::getCaseCible() const
{
    return _modele->getCaseCible();
}

void ModelePourQML::annulerSelections()
{
    _modele->annulerSelections();
}

uint16_t ModelePourQML::getNbActionsPossibles() const
{
    return _modele->getNbActionsPossibles();
}

void ModelePourQML::choixAction(uint16_t indAction)
{
    if (getUniteSelectionee())
        _modele->choixAction(indAction);
}

void ModelePourQML::effectuerAction()
{
    _modele->effectuerAction();
}

QString ModelePourQML::getFactionAttaquante() const
{
    return (_modele->getFactionAttaquante() == Faction::bleue) ? "blue" : "red";
}

bool ModelePourQML::actionValidable() const
{
    return getCaseSelectionnee() && getCaseCible();
}

bool ModelePourQML::actionAnnulable() const
{
    return getCaseSelectionnee();
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
    if (auto unit = _modele->getUniteSelectionee())
    {
        return QString::fromStdString("PV : "+std::to_string(unit->getPointsVie())+"/"+std::to_string(unit->getMaxPointsVie())+"\n" +
                "Munitions : "+std::to_string(unit->getNbMunitions())+"/"+std::to_string(unit->getMaxNbMunitions())+"\n" +
                "Provisions : "+std::to_string(unit->getNbProvisions())+"/"+std::to_string(unit->getMaxNbProvisions()));
    }
    return "";
}
