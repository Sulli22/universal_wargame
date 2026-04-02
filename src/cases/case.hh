#pragma once

#include "position.hh"
#include "uniteaerienne.hh"

class Case {
public:
    Case(const Position &pos);

    const Position &getPos() const;
    std::shared_ptr<UniteAerienne> getUniteAerienne() const;
    void setUniteAerienne(std::shared_ptr<UniteAerienne> nvUniteAerienne);

    void deplacerUniteAerienne(Case &arrive);

private:
    Position _pos;
    std::shared_ptr<UniteAerienne> _uniteAerienne;
};


