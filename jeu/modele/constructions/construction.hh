#pragma once

#include "unite.hh"
#include <vector>

using usint = unsigned short int;

class Construction {
public:
    Construction(usint cout);

    usint getCout() const;

    void effectuerAction(std::vector<Unite *> unites) const;
    virtual bool estPont() const;

protected:
    virtual void effectuerAction(Unite *unite) const =0;

private:
    usint _cout;
};

