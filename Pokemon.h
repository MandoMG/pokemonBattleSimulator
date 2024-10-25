//
// Created by Armando Meza on 10/23/24.
//

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon {
    private:
        std::string moveSet[4]; // std::vector could be used if we need a dynamic array
        int healthPoints;
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
};



#endif //POKEMON_H
