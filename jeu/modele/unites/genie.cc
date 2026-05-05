#include "genie.hh"

Genie::Genie(Faction faction, uint16_t pointsVie, uint16_t nbMuntions, uint16_t nbProvisions):
    Unite(faction, pointsVie, nbMuntions, nbProvisions),
    Infanterie(faction, pointsVie, nbMuntions, nbProvisions)
{}

std::string Genie::getNom() const
{
    return Infanterie::getNom() + " - Genie";
}

uint16_t Genie::getNbActionsPossibles() const
{
    return Unite::getNbActionsPossibles() + 1;  // on ajoute la construction
}

void Genie::construire(CaseTerrestre *caseOuConstruire, std::unique_ptr<Construction> construction)
{
    utiliserProvisions(construction->getCout());
    caseOuConstruire->setConstruction(std::move(construction));
}
