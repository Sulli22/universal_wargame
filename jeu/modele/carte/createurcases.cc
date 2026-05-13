#include "createurcases.hh"

#include "casemarine.hh"
#include "caseterrestre.hh"


std::unique_ptr<Case> CreateurCases::creer(char c, const Position &pos)
{
    switch (c) {
    case 'E':
        return std::make_unique<CaseMarine>(pos);
    case 'P':
        return std::make_unique<CaseTerrestre>(pos, TypeTerrain::plaine);
    case 'F':
        return std::make_unique<CaseTerrestre>(pos, TypeTerrain::foret);
    case 'M':
        return std::make_unique<CaseTerrestre>(pos, TypeTerrain::montagne);
    case 'R':
        return std::make_unique<CaseTerrestre>(pos, TypeTerrain::riviere);

    default:
        throw std::runtime_error("Erreur : type de case " + std::to_string(c) +" non prit en charge");
    }
}
