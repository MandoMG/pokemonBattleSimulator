//
// Created by Armando Meza on 10/23/24.
//

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
    private:
        std::string moveSet[4]; // std::vector could be used if we need a dynamic array
        int healthPoints;
        int attackStat;
        int defenseStat;
        int spAttackStat;
        int spDefenseStat;
        int speed;
    public:
        Pokemon(std::string pkmnName, int lvl);

        // properties
        std::string name;
        int level;

        // methods
        void displayInfo() const;
        void displayHealthPoints() const;
        void setHealthPoints(int hp);
        void setDamageReceived(int inflictedDamage);
        int getAttackStat(bool isSpecialMove) const;
        int getDefenseStat(bool isSpecialMove) const;
        int getHealthPoints() const;
        int getSpeedStat() const;
};

#endif //POKEMON_H
