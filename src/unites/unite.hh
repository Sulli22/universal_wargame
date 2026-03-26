#pragma once

#include <ostream>
#include <memory>

class Unite {
public:
    Unite(unsigned int pointsVie,
          unsigned int nbMunitions);

    unsigned int getPointsVie() const;
    unsigned int getNbMunitions() const;

    virtual unsigned int getPointsAttaqueLegere() const =0;
    virtual unsigned int getPointsAttaqueLourde() const =0;
    virtual unsigned int getCapaciteDeplacement() const =0;
    virtual unsigned int getDistanceAttaque() const =0;

    virtual bool estLegere() const =0;
    bool estOperationnelle() const;
    virtual void prendreDegats(unsigned int degats);
    void attaquerUnite(std::shared_ptr<Unite> unite);

    virtual void sortieFlux(std::ostream &os) const;

private:
    unsigned int _pointsVie;
    unsigned int _nbMunitions;
};
