#pragma once

#include "unite.hh"
#include <vector>

class Construction {
public:
    Construction(stat cout);

    stat getCout() const;

    void effectuerAction(std::vector<Unite *> unites) const;
    virtual bool estPont() const;

protected:
    virtual void effectuerAction(Unite *unite) const =0;

private:
    stat _cout;
};

