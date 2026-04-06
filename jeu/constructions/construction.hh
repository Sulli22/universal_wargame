#pragma once

using usint = unsigned short int;

class Construction {
public:
    Construction(usint cout);

    usint getCout() const;

    virtual bool estPont() const;

private:
    usint _cout;
};

