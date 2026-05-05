#pragma once

#include "unite.hh"
#include <vector>
#include <cstdint>

class Construction {
public:
    Construction(uint16_t cout);

    uint16_t getCout() const;

    void effectuerAction(std::vector<Unite *> unites) const;
    virtual bool estPont() const;

protected:
    virtual void effectuerAction(Unite *unite) const =0;

private:
    uint16_t _cout;
};

