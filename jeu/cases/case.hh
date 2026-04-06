#pragma once

#include "position.hh"
#include "uniteaerienne.hh"

class Case {
public:
    Case(const Position &pos);

    const Position &getPos() const;
    const UniteAerienne *getUniteAerienne() const;
    void setUniteAerienne(std::unique_ptr<UniteAerienne> nvUniteAerienne);

    void deplacerUniteAerienne(Case &arrive);

    virtual usint coupDeplacement(std::unique_ptr<Unite> unite) const =0;

private:
    Position _pos;
    std::unique_ptr<UniteAerienne> _uniteAerienne;
};


