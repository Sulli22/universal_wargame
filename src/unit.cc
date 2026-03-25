#include "unit.hh"

/*
 *      Constructeur
 */
Unit::Unit(int healthPoints, int attackPoints, int travelCapacity) :
    _healthPoints(healthPoints),
    _attackPoints(attackPoints),
    _travelCapacity(travelCapacity)
{}

/*
 *      Getters et Setters
 */
int Unit::getHealthPoints() const
{
    return _healthPoints;
}

int Unit::getAttackPoints() const
{
    return _attackPoints;
}

int Unit::getTravelCapacity() const
{
    return _travelCapacity;
}

void Unit::setHealthPoints(int newHealthPoints)
{
    _healthPoints = newHealthPoints;
}

void Unit::setAttackPoints(int newAttackPoints)
{
    _attackPoints = newAttackPoints;
}

void Unit::setTravelCapacity(int newTravelCapacity)
{
    _travelCapacity = newTravelCapacity;
}

void Unit::attackUnit(Unit &unit)
{
    unit.setHealthPoints(unit.getHealthPoints()-_attackPoints);
}
