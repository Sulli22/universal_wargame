#pragma once

#include "unite.hh"
#include <vector>

class Construction {
public:
    Construction();

    virtual Stat getCout() const = 0;

    void effectuerEffet(std::vector<Unite *> unites) const;
    virtual bool estPont() const;

protected:
    virtual void effectuerEffet(Unite *unite) const =0;
};

// utilisation d'un template permettant des tests du le cout sans instances
template<typename Derivee>
class ConstructionTemplate: public Construction {
public:
    ConstructionTemplate();

    Stat getCout() const override { return Derivee::getCoutImpl(); }
    static Stat getCoutStatic() { return Derivee::getCoutImpl(); }
};
