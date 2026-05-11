#include "genie.hh"

Genie::Genie(Faction faction, stat pointsVie, stat nbMuntions, stat nbProvisions):
    Unite(faction, pointsVie, nbMuntions, nbProvisions),
    Infanterie(faction, pointsVie, nbMuntions, nbProvisions)
{}

std::string Genie::getNom() const
{
    return Infanterie::getNom() + " - Genie";
}

std::set<indiceAction> Genie::getIndicesActionsPossibles() const
{
    auto indices = Unite::getIndicesActionsPossibles();

    if (getNbProvisions() > 0)
        indices.insert(2);      // on ajoute la construction

    return indices;
}

void Genie::construire(CaseTerrestre *caseOuConstruire, std::unique_ptr<Construction> construction)
{
    utiliserProvisions(construction->getCout());
    caseOuConstruire->setConstruction(std::move(construction));
}
