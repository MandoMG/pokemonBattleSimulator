//
// Created by Armando Meza on 11/2/24.
//

#ifndef POKEMONMOVE_H
#define POKEMONMOVE_H

#include <string>
#include "types/Enums.h"

class PokemonMove
{
    private:
        std::string moveName;
        std::string moveType;
        int basePwr;
        MoveCategory moveCategory;
    public:
        PokemonMove(std::string name, int basePower, std::string type, MoveCategory moveCategory);

        bool isSpecial() const;
        bool isStatus() const;
        int getBasePower() const;
        std::string getName();
        std::string getType();
};

#endif //POKEMONMOVE_H
