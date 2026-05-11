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

bool ModelePourQML::cheminExiste() const
{
    return _modele->cheminExiste();
}

std::vector<Case *> ModelePourQML::getChemin() const
{
    return _modele->getChemin();
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
    return _modele->actionValidable();
}

bool ModelePourQML::actionAnnulable() const
{
    return getCaseSelectionnee();
}

uint16_t ModelePourQML::getNbConstructionsPossibles() const
{
    // 0 si aucunes
    // 1 si juste pont
    // 3 si infirmerie + depots
    return _modele->getNbConstructionsPossibles();
}

void ModelePourQML::choixConstruction(uint16_t indConstruction)
{
    /*
        case 0:     _aConstruire = std::make_unique<DepotMunitions>();  break;
        case 1:     _aConstruire = std::make_unique<DepotProvisions>(); break;
        case 2:     _aConstruire = std::make_unique<Infirmerie>();      break;
        case 3:     _aConstruire = std::make_unique<Pont>();            break;
    */
    _modele->choixConstruction(indConstruction);
}

bool ModelePourQML::partieFinie() const
{
    return _modele->partieFinie();
}

QString ModelePourQML::getFactionVictorieuse() const
{
    return (_modele->getFactionVictorieuse() == Faction::bleue) ? "blue" : "red";
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

void ModelePourQML::changerJoueur()
{
    _modele->changerJoueur();
}

QString ModelePourQML::getStatsUniteSelectionee() const
{
    if (auto unit = _modele->getUniteSelectionee()) {
        QString stats =  tr("PV") + " : "+QString::number(unit->getPointsVie())+"/"+QString::number(unit->getMaxPointsVie())+"\n";
        if (!unit->estLegere())
        {
            UniteLourde* uniteCast = dynamic_cast<UniteLourde*>(unit);
            stats += tr("Bouclier")+": "+QString::number(uniteCast->getPointsBouclier())+"/"+QString::number(uniteCast->getMaxPointsBouclier())+"\n";

        }
        stats += tr("Munitions") +" : "+QString::number(unit->getNbMunitions())+"/"+QString::number(unit->getMaxNbMunitions())+"\n" +
                tr("Provisions") +" : "+QString::number(unit->getNbProvisions())+"/"+QString::number(unit->getMaxNbProvisions());
        return stats;
    }
    return tr("Pas d'unité");
}
