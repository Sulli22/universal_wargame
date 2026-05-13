#include "caseterrestre.hh"

#include "unitemarine.hh"
#include "uniteterrestrelegere.hh"
#include "uniteterrestrelourde.hh"
#include "genie.hh"
#include "depotmunitions.hh"
#include "depotprovisions.hh"
#include "infirmerie.hh"
#include "pont.hh"

#include <iostream>
#include <limits>

CaseTerrestre::CaseTerrestre(const Position &pos, TypeTerrain terrain,
                             Stat espaceDisponible):
    Case(pos), _espaceDisponible(espaceDisponible), _terrain(terrain)
{}

TypeTerrain CaseTerrestre::getTerrain() const
{
    return _terrain;
}

Construction *CaseTerrestre::getConstruction() const
{
   return _construction.get();
}

void CaseTerrestre::deplacerUnite(std::size_t indUnite, Case *arrivee, Stat cout)
{
    if (indUnite == 0 && getUniteAerienne())         // s'il y a une unite aerienne et ind = 0
        Case::deplacerUniteAerienne(arrivee, cout); // on deplace l'unite aerienne

    else {  // sinon on deplace unite terreste
        auto ct = dynamic_cast<CaseTerrestre *>(arrivee);
        auto dec = getUniteAerienne() ? 1 : 0;
        deplacerUniteTerrestre(indUnite-dec, ct, cout);
    }
}

void CaseTerrestre::supprimeNonUnitesOperationnelles()
{
    Case::supprimeNonUnitesOperationnelles();
    for (auto it = _unitesTerrestres.begin(); it != _unitesTerrestres.end(); ) {
        if (!(*it)->estOperationnelle())
            it = _unitesTerrestres.erase(it);
        else
            ++it;
    }
}

void CaseTerrestre::ajouterUniteTerrestre(std::unique_ptr<UniteTerrestre>
                                              nvUniteTerrestre)
{
    if (!nvUniteTerrestre)
        throw  std::invalid_argument("Erreur : une unite nulle ne peut pas être ajoutée");

    if (getFaction() != Faction::neutre &&
        nvUniteTerrestre->getFaction() != getFaction())
        throw std::invalid_argument("Erreur : la nouvelle unite n'appartient pas à la faction");

    if (nvUniteTerrestre->estLegere()) {
        auto uniteTerrestreLeg = dynamic_cast<UniteTerrestreLegere *>(nvUniteTerrestre.get());

        if (uniteTerrestreLeg->getTaille() <= _espaceDisponible) {  // on vérifie qu'il y a la place d'ajouter
            // les forets reduise la visibilité des unités qui y sont
            if (_terrain == TypeTerrain::foret)
                nvUniteTerrestre->setVisibilite(Unite::Visibilite::partielle);
            else
                nvUniteTerrestre->setVisibilite(Unite::Visibilite::totale);

            // on ajoute l'unite et on enleve de l'espace dispo la taille qu'elle prend
            _unitesTerrestres.push_back(std::move(nvUniteTerrestre));
            _espaceDisponible -= uniteTerrestreLeg->getTaille();
        }

        else
            throw std::runtime_error("Erreur : Ajout impossible, place est insufisante");
    }

    else if (_espaceDisponible == _MAX_ESPACE) {    // une unité lourde prend tout l'espace
        _unitesTerrestres.push_back(std::move(nvUniteTerrestre));
        _espaceDisponible = 0;
    }

    else
        throw std::runtime_error("Erreur : Ajout impossible, place est insufisante (toute la place est necessaire pour une unite lourde)");
}

void CaseTerrestre::setConstruction(std::unique_ptr<Construction> nvConstruction)
{
    if (_construction)
        throw std::runtime_error("Erreur : la place est déja prise");

    if (_terrain == TypeTerrain::riviere) {
        // seul un pont peut etre construit
        if (nvConstruction->estPont())
            _construction = std::move(nvConstruction);
        else
            throw std::runtime_error("Erreur : la case est une rivière");
    }

    else if (_terrain != TypeTerrain::plaine)   // les plaines sont les seuls autres terrains constructibles
        throw std::runtime_error("Erreur : ce type de case n'est pas constructible");

    else if (nvConstruction->estPont())         // mais ça ne peut pas être un pont
        throw std::invalid_argument("Erreur : la construction ne peut pas etre un pont");

    else
        _construction = std::move(nvConstruction);      // on construit
}

void CaseTerrestre::effectuerEffetConstruction()
{
    if (_construction)
        _construction->effectuerEffet(getUnites());
}

std::vector<Unite *> CaseTerrestre::getUnites() const
{
    auto unites = Case::getUnites();
    for (auto &u : _unitesTerrestres)
        unites.push_back(u.get());
    return unites;
}

std::size_t CaseTerrestre::nbUnites() const
{
    return Case::nbUnites() + _unitesTerrestres.size();
}

Stat CaseTerrestre::coutDeplacement(Unite *unite) const
{
    auto max = std::numeric_limits<Stat>::max();
    if (!peutAccueillir(unite))
        return max;             // infranchissable si accueil impossible

    auto pUniteAerienne = dynamic_cast<UniteAerienne *>(unite);
    if (pUniteAerienne)
        return 1;               // toujours franchissable avec cout 1 pour unités aeriennes

    auto pUniteMarine = dynamic_cast<UniteMarine *>(unite);
    if (pUniteMarine)
        return max;         // infranchissable par les unites marines

    switch (_terrain) {
    // plaine franchissable avec cout 1
    case TypeTerrain::plaine:   return 1;

    // la foret à un cout de 2 si l'unité est lourde
    case TypeTerrain::foret:    return unite->estLegere() ? 1 : 2;

    // si il n'y a pas de pont la riviere est infranchissable
    case TypeTerrain::riviere:  return _construction && _construction->estPont() ? 1 : max;

    // montagnes toujours infranchissable
    case TypeTerrain::montagne: return max;

    default:
        throw std::runtime_error("Erreur : Impossible de calculer le cout de deplacement");
    }
}

Faction CaseTerrestre::getFaction() const
{
    auto faction = Case::getFaction();

    if (faction != Faction::neutre)
        return faction;

    if (!_unitesTerrestres.empty())
        return _unitesTerrestres[0]->getFaction();

    return Faction::neutre;
}

std::vector<IndiceConstruction> CaseTerrestre::getIndicesConstructionsPossibles(const Genie &genie) const
{
    if (_construction
        || _terrain == TypeTerrain::foret
        || _terrain == TypeTerrain::montagne)
        return {};   // rien ne peut etre construit

    if (_terrain == TypeTerrain::riviere) {
        if (genie.peutDepenser(Pont::getCoutStatic()))
            return {3}; // pont uniquement
        return {};
    }

    // sinon on vérfie seulement le cout
    std::vector<IndiceConstruction> res;

    if (genie.peutDepenser(DepotMunitions::getCoutStatic()))
        res.push_back(0);

    if (genie.peutDepenser(DepotProvisions::getCoutStatic()))
        res.push_back(1);

    if (genie.peutDepenser(Infirmerie::getCoutStatic()))
        res.push_back(2);

    return res;
}

void CaseTerrestre::afficherDetails(std::ostream &os) const
{
    Case::afficherDetails(os); os << std::endl;

    os << "Type = ";
    switch (_terrain) {
    case TypeTerrain::plaine:   os << "Plaine";     break;
    case TypeTerrain::foret:    os << "Foret";      break;
    case TypeTerrain::riviere:  os << "Riviere";    break;
    case TypeTerrain::montagne: os << "Montagne";   break;
    }
    os << std::endl;

    os << "Espace dispo = " << _espaceDisponible << std::endl;

    os <<  "Construction ? " << (_construction != nullptr) << std::endl;
}

bool CaseTerrestre::peutAccueillir(Unite *unite) const
{
    auto ua = dynamic_cast<UniteAerienne *>(unite);
    if (ua && !getUniteAerienne())
        return true;

    auto utLeg = dynamic_cast<UniteTerrestreLegere *>(unite);
    if (utLeg && (_espaceDisponible >= utLeg->getTaille()))
        return true;

    auto utLourde = dynamic_cast<UniteTerrestreLourde *>(unite);
    if (utLourde && (_espaceDisponible == _MAX_ESPACE))
        return true;

    return false;
}

void CaseTerrestre::deplacerUniteTerrestre(std::size_t indUnite, CaseTerrestre *arrivee, Stat cout)
{
    if (_unitesTerrestres.at(indUnite)->estLegere()) {
        // si unite est legere alors on rajoute à l'espace dispo la place quelle prennait
        auto uniteTerrestreLeg = dynamic_cast<UniteTerrestreLegere *>
            (_unitesTerrestres.at(indUnite).get());
        _espaceDisponible += uniteTerrestreLeg->getTaille();
    }

    else    // sinon on reset l'espace dispo
        _espaceDisponible = _MAX_ESPACE;

    _unitesTerrestres.at(indUnite)->utiliserProvisions(cout);                   // se déplacer à un cout en provision
    arrivee->ajouterUniteTerrestre(std::move(_unitesTerrestres.at(indUnite)));  // on ajoute l'unité à l'arrivee
    _unitesTerrestres.erase(_unitesTerrestres.begin() + indUnite);              // on oubli pas de supprimer le unique_ptr null de la case
}
