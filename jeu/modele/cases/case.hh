#pragma once

#include "position.hh"
#include "uniteaerienne.hh"
#include <memory>
#include <vector>

using indiceConstruction = unsigned int;

class Genie;

class Case {
public:
    Case(const Position &pos);

    const Position &getPos() const;
    const UniteAerienne *getUniteAerienne() const;

    void setUniteAerienne(std::unique_ptr<UniteAerienne> nvUniteAerienne);

    virtual Unite *getUnite(std::size_t indUnite);
    virtual void deplacerUnite(std::size_t indUnite, Case *arrivee, stat cout) =0;
    virtual std::vector<Unite *> getUnites() const;
    virtual stat coutDeplacement(Unite *unite) const =0;
    virtual Faction getFaction() const;
    virtual std::size_t nbUnites() const;
    bool estConstructible(const Genie &genie) const;
    virtual std::vector<indiceConstruction> getIndicesConstructionsPossibles(const Genie &genie) const =0;
    virtual void supprimeNonUnitesOperationnelles();

// sortie flux
    void sortieFlux(std::ostream &os) const;
    virtual void afficherDetails(std::ostream &os) const;

protected:
    void deplacerUniteAerienne(Case *arrive, stat cout);
    virtual bool peutAccueillir(Unite *unite) const =0;

private:
    Position _pos;
    std::unique_ptr<UniteAerienne> _uniteAerienne;
};


