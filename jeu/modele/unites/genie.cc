#include "genie.hh"

Genie::Genie(Faction faction, Stat pointsVie, Stat nbMuntions, Stat nbProvisions):
    Unite(faction, pointsVie, nbMuntions, nbProvisions),
    Infanterie(faction, pointsVie, nbMuntions, nbProvisions)
{}

std::string Genie::getNom() const
{
    return Infanterie::getNom() + " - Genie";
}

std::vector<IndiceAction> Genie::getIndicesActionsPossibles() const
{
    auto indices = Unite::getIndicesActionsPossibles();

    if (getNbProvisions() > 0)
        indices.push_back(2);      // on ajoute la construction

    return indices;
}

void Genie::rechargerProvisions()
{
    // ne rien faire
    // un genie ne peut pas regagner des provisions
}

bool Genie::peutDepenser(Stat cout) const
{
    return (getNbProvisions() >= cout);
}

void Genie::construire(CaseTerrestre *caseOuConstruire, std::unique_ptr<Construction> construction)
{
    auto cout = construction->getCout();
    if (getNbProvisions() >= cout) {
        utiliserProvisions(cout);
        caseOuConstruire->setConstruction(std::move(construction));
    }
}
