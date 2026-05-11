#pragma once

#include "unite.hh"
#include <vector>

class Construction {
public:
    Construction();

    virtual stat getCout() const = 0;

    void effectuerAction(std::vector<Unite *> unites) const;
    virtual bool estPont() const;

protected:
    virtual void effectuerAction(Unite *unite) const =0;
};

template<typename Derive>
class ConstructionTemplate: public Construction {
public:
    ConstructionTemplate();

    stat getCout() const override { return Derive::getCoutImpl(); }

    static stat getCoutStatic() { return Derive::getCoutImpl(); }
};

