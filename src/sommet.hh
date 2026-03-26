#pragma once
#include <memory>
#include "uniteaerienne.hh"

class Sommet
{
public:
    Sommet();

    std::shared_ptr<UniteAerienne> getUniteHaute() const;

    void setUniteHaute(std::shared_ptr<UniteAerienne> nvUniteAerienne);

private:
    std::shared_ptr<UniteAerienne> _uniteHaute;
};

