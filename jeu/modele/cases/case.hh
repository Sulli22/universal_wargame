#pragma once

#include "position.hh"
#include "uniteaerienne.hh"
#include <memory>
#include <vector>

using IndiceConstruction = unsigned int;

class Genie;

class Case {
public:
    Case(const Position &pos);

// getters
    const Position &getPos() const;
    const UniteAerienne *getUniteAerienne() const;

// méthodes jeu
    void setUniteAerienne(std::unique_ptr<UniteAerienne> nvUniteAerienne);
    virtual void deplacerUnite(std::size_t indUnite, Case *arrivee, Stat cout) =0;
    virtual void supprimeNonUnitesOperationnelles();

    virtual std::vector<Unite *> getUnites() const;
    virtual std::size_t nbUnites() const;
    virtual Unite *getUnite(std::size_t indUnite) const;
    virtual Stat coutDeplacement(Unite *unite) const =0;
    virtual Faction getFaction() const;
    bool estConstructible(const Genie &genie) const;
    virtual std::vector<IndiceConstruction> getIndicesConstructionsPossibles(const Genie &genie) const =0;

// sortie flux
    void sortieFlux(std::ostream &os) const;
    virtual void afficherDetails(std::ostream &os) const;

protected:
    void deplacerUniteAerienne(Case *arrive, Stat cout);
    virtual bool peutAccueillir(Unite *unite) const =0;

private:
    Position _pos;
    std::unique_ptr<UniteAerienne> _uniteAerienne;
};


