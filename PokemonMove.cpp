//
// Created by Armando Meza on 11/2/24.
//

#include <iostream>
#include "PokemonMove.h"

// Constructor definition
PokemonMove::PokemonMove(std::string name, int basePower, std::string type, MoveCategory category)
{
    moveName = name;
    basePwr = basePower;
    moveType = type;
    moveCategory = category;
}

std::string PokemonMove::getName()
{
    return moveName;
}

std::string PokemonMove::getType()
{
    return moveType;
}

bool PokemonMove::isSpecial() const
{
    return moveCategory == MoveCategory::SPECIAL;
}

bool PokemonMove::isStatus() const
{
    return moveCategory == MoveCategory::STATUS;
}

int PokemonMove::getBasePower() const
{
    return basePwr;
}