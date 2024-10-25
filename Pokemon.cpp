//
// Created by Armando Meza on 10/23/24.
//

#include <iostream>
#include "Pokemon.h"

// Constructor definition
Pokemon::Pokemon(std::string pkmnName, int lvl) {
    name = pkmnName;
    level = lvl;
    healthPoints = 100;
}

void Pokemon::displayInfo() const {
    std::cout << "Your Pokemon is: " << name << " of level: " << level << std::endl;
}

void Pokemon::displayHealthPoints() const {
    std::cout << "Your Pokemon current HP is: : " << healthPoints << std::endl;
}

void Pokemon::setDamageReceived(int inflictedDamage) {
    int currentHealthPoints = healthPoints - inflictedDamage;

    if (currentHealthPoints <= 0) {
        healthPoints = 0;
    } else {
        healthPoints = currentHealthPoints;
    }
}

