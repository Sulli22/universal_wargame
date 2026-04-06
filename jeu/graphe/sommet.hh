#pragma once

#include <memory>
#include "uniteaerienne.hh"

class Sommet {
public:
    Sommet();

    std::shared_ptr<UniteAerienne> getUniteHaute() const;
    unsigned int getId() const;
    void setUniteHaute(std::shared_ptr<UniteAerienne> nvUniteAerienne);

private:
    std::shared_ptr<UniteAerienne> _uniteHaute;
    unsigned int _id;
    static unsigned int _nextId;
};

