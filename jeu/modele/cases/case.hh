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
    virtual void deplacerUnite(std::size_t indUnite, Case *arrivee, uint16_t cout) =0;
    virtual std::vector<Unite *> getUnites() const;
    virtual uint16_t coutDeplacement(Unite *unite) const =0;
    virtual Faction getFaction() const;
    virtual uint16_t nbUnites() const;
    bool estConstructible() const;
    virtual uint16_t nbConstructionsPossibles() const =0;
    virtual void supprimeNonUnitesOperationnelles();

// sortie flux
    void sortieFlux(std::ostream &os) const;
    virtual void afficherDetails(std::ostream &os) const;

protected:
    void deplacerUniteAerienne(Case *arrive, uint16_t cout);
    virtual bool peutAccueillir(Unite *unite) const =0;

private:
    Position _pos;
    std::unique_ptr<UniteAerienne> _uniteAerienne;
};


