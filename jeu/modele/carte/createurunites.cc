#include "createurunites.hh"
#include "artillerie.hh"
#include "charassaut.hh"
#include "fregate.hh"
#include "infanterie.hh"
#include "sousmarin.hh"
#include "bombardier.hh"
#include "genie.hh"
#include "chasseur.hh"

Faction CreateurUnites::charToFaction(char factionChar)
{
    return (factionChar == 'B') ? Faction::bleue : Faction::rouge;
}

std::unique_ptr<UniteAerienne> CreateurUnites::creerAerienne(char type, char factionChar)
{
    auto faction = charToFaction(factionChar);

    if (type == 'C')
        return std::make_unique<Chasseur>(faction);

    return std::make_unique<Bombardier>(faction);
}

std::unique_ptr<UniteMarine> CreateurUnites::creerMarine(char type, char factionChar)
{
    auto faction = charToFaction(factionChar);

    if (type == 'F') return std::make_unique<Fregate>(faction);
    if (type == 'S') return std::make_unique<SousMarin>(faction);

    throw std::runtime_error("Erreur : Impossible de creer cette unite.");
}

std::unique_ptr<UniteTerrestre> CreateurUnites::creerTerrestre(char type, char factionChar)
{
    auto faction = charToFaction(factionChar);

    if (type == 'I') return std::make_unique<Infanterie>(faction);
    if (type == 'A') return std::make_unique<Artillerie>(faction);
    if (type == 'T') return std::make_unique<CharAssaut>(faction);
    if (type == 'G') return std::make_unique<Genie>(faction);

    throw std::runtime_error("Erreur : Impossible de creer cette unite.");
}
