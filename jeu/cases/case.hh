#pragma once

#include "position.hh"
#include "uniteaerienne.hh"
#include <memory>
#include <vector>

class Case {
public:
    Case(const Position &pos);

    const Position &getPos() const;
    const UniteAerienne *getUniteAerienne() const;

    void setUniteAerienne(std::unique_ptr<UniteAerienne> nvUniteAerienne);

    virtual Unite *getUnite(std::size_t indUnite);
    virtual void deplacerUnite(std::size_t indUnite, Case *arrivee, usint cout) =0;
    virtual std::vector<Unite *> getUnites() const;
    virtual usint coutDeplacement(Unite *unite) const =0;
    virtual Faction getFaction() const;
    virtual usint nbUnites() const;
    bool estConstructible() const;
    virtual usint nbConstructionsPossibles() const =0;
    virtual void supprimeNonUnitesOperationnelles();

// sortie flux
    void sortieFlux(std::ostream &os) const;
    virtual void afficherDetails(std::ostream &os) const;

protected:
    void deplacerUniteAerienne(Case *arrive, usint cout);
    virtual bool peutAccueillir(Unite *unite) const =0;

private:
    Position _pos;
    std::unique_ptr<UniteAerienne> _uniteAerienne;
};


