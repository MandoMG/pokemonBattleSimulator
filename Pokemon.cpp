//
// Created by Armando Meza on 10/23/24.
//

#include <iostream>
#include "Pokemon.h"

// Constructor definition
Pokemon::Pokemon(std::string pkmnName, int lvl, bool isPlayerPkmn)
{
    name = pkmnName;
    level = lvl;
    healthPoints = 40;
    attackStat = 52;
    defenseStat = 43;
    spAttackStat = 60;
    spDefenseStat = 50;
    speed = 65;
    isPlayerPokemon = isPlayerPkmn;

    setPokemonMoveSet();
}

void Pokemon::setPokemonMoveSet()
{
    // std::string name, int basePower, std::string type, bool isSpecial
    const PokemonMove growl("Growl", 0, "Normal", MoveCategory::STATUS);

    if(name == "Charmander") {
            const PokemonMove scratch("Scratch", 40, "Normal", MoveCategory::PHYSICAL);
            const PokemonMove ember("Ember", 40, "Fire", MoveCategory::SPECIAL);
            const PokemonMove smokeScreen("Smokescreen", 0, "Normal", MoveCategory::STATUS);

            moveSet.push_back(growl);
            moveSet.push_back(scratch);
            moveSet.push_back(ember);
            moveSet.push_back(smokeScreen);
    } else if (name == "Pikachu") {
            const PokemonMove tackle("Tackle", 40, "Normal", MoveCategory::PHYSICAL);
            const PokemonMove thunderShock("Thunder Shock", 40, "Thunder", MoveCategory::SPECIAL);
            const PokemonMove tailWhip("Tail Whip", 0, "Normal", MoveCategory::STATUS);

            moveSet.push_back(growl);
            moveSet.push_back(tackle);
            moveSet.push_back(thunderShock);
            moveSet.push_back(tailWhip);
    }
}


void Pokemon::displayInfo() const
{
    if (isPlayerPokemon) {
        std::cout << "Your Pokemon is: " << name << " of level: " << level << std::endl;
    } else {
        std::cout << "Enemy Pokemon is: " << name << " of level: " << level << std::endl;
    }
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

std::vector<PokemonMove> Pokemon::getPokemonMoveSet()
{
    return moveSet;
}
