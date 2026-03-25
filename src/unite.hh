#pragma once

#include <ostream>
//#include <string>

class Unite {
public:
    Unite(int pointsVie, int pointsAttaque, int capaciteDeDeplacement, unsigned int distanceAttaque=0);

    int getPointsVie() const;
    int getPointsAttaque() const;
    int getCapaciteDeDeplacement() const;
    void setPointsVie(int nvPointsVie);
    void setPointsAttaque(int nvPointsAttaque);
    void setCapaciteDeDeplacement(int nvCapaciteDeDeplacement);

    void attaquerUnite(Unite &unite);

    virtual void sortieFlux(std::ostream &os) const;
    //virtual std::string getType() const =0;

private:
    int _pointsVie;
    int _pointsAttaque;
    int _capaciteDeDeplacement;
    unsigned int _distanceAttaque;
};
