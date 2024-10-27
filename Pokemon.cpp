//
// Created by Armando Meza on 10/23/24.
//

#include <iostream>
#include "Pokemon.h"

// Constructor definition
Pokemon::Pokemon(std::string pkmnName, int lvl)
{
    name = pkmnName;
    level = lvl;
    healthPoints = 40;
    attackStat = 52;
    defenseStat = 43;
    spAttackStat = 60;
    spDefenseStat = 50;
    speed = 65;
}

void Pokemon::displayInfo() const
{
    std::cout << "Your Pokemon is: " << name << " of level: " << level << std::endl;
}

void Pokemon::displayHealthPoints() const
{
    std::cout << name << "'s current HP is: " << healthPoints << std::endl;
}

void Pokemon::setDamageReceived(int inflictedDamage)
{
    int currentHealthPoints = healthPoints - inflictedDamage;

    if (currentHealthPoints <= 0) {
        healthPoints = 0;
    } else {
        healthPoints = currentHealthPoints;
    }
}

int Pokemon::getAttackStat(bool isSpecialMove) const
{
    return isSpecialMove ? spAttackStat : attackStat;
}

int Pokemon::getDefenseStat(bool isSpecialMove) const
{
    return isSpecialMove ? spDefenseStat : defenseStat;
}

int Pokemon::getHealthPoints() const
{
    return healthPoints;
}

int Pokemon::getSpeedStat() const
{
    return speed;
}
