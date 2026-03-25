#pragma once

//#include <string>

class Unit {
public:
    Unit(int healthPoints, int attackPoints, int travelCapacity);

    int getHealthPoints() const;
    int getAttackPoints() const;
    int getTravelCapacity() const;
    void setHealthPoints(int newHealthPoints);
    void setAttackPoints(int newAttackPoints);
    void setTravelCapacity(int newTravelCapacity);

    void attackUnit(Unit &unit);

    //virtual std::string getType() const =0;

private:
    int _healthPoints;
    int _attackPoints;
    int _travelCapacity;
};
