#pragma once

#include "unite.hh"
#include <vector>

class Construction {
public:
    Construction();

    virtual stat getCout() const = 0;

    void effectuerEffet(std::vector<Unite *> unites) const;
    virtual bool estPont() const;

protected:
    virtual void effectuerEffet(Unite *unite) const =0;
};

// utilisation d'un template permettant des tests du le cout sans instances
template<typename Derive>
class ConstructionTemplate: public Construction {
public:
    ConstructionTemplate();

    stat getCout() const override { return Derive::getCoutImpl(); }
    static stat getCoutStatic() { return Derive::getCoutImpl(); }
};
