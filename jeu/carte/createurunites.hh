#pragma once

#include "uniteaerienne.hh"
#include "unitemarine.hh"
#include "uniteterrestre.hh"
#include <memory>

class CreateurUnites {
public:
    static Faction charToFaction(char factionChar);

    static std::unique_ptr<UniteAerienne> creerAerienne(char type,
                                                        char factionChar);
    static std::unique_ptr<UniteMarine> creerMarine(char type,
                                                    char factionChar);
    static std::unique_ptr<UniteTerrestre> creerTerrestre(char type,
                                                          char factionChar);
};
