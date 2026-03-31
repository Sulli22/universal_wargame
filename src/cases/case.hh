#pragma once

#include "position.hh"
#include "uniteaerienne.hh"

class Case {
public:
    Case(const Position &pos);

    const Position &getPos() const;
    std::shared_ptr<UniteAerienne> getUniteHaute() const;
    void setUniteHaute(std::shared_ptr<UniteAerienne> nvUniteAerienne);

private:
    Position _pos;
    std::shared_ptr<UniteAerienne> _uniteHaute;
};


