#pragma once

#include "position.hh"
#include "uniteaerienne.hh"
#include <vector>

class Case {
public:
    Case(const Position &pos);

    const Position &getPos() const;
    const UniteAerienne *getUniteAerienne() const;

    void setUniteAerienne(std::unique_ptr<UniteAerienne> nvUniteAerienne);

    virtual bool peutAccueillir(Unite *unite) const =0;
    void deplacerUniteAerienne(Case *arrive);
    virtual Unite *getUnite(std::size_t indUnite);
    virtual void deplacerUnite(std::size_t indUnite, Case *arrivee) =0;
    virtual std::vector<Unite *> getUnites() const;
    virtual usint coutDeplacement(Unite *unite) const =0;
    virtual Faction getFaction() const;

    void sortieFlux(std::ostream &os) const;
    virtual void afficherDetails(std::ostream &os) const;

private:
    Position _pos;
    std::unique_ptr<UniteAerienne> _uniteAerienne;
};


