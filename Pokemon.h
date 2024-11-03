//
// Created by Armando Meza on 10/23/24.
//

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "PokemonMove.h"

class Pokemon
{
    private:
        std::vector<PokemonMove> moveSet;
        int healthPoints;
        int attackStat;
        int defenseStat;
        int spAttackStat;
        int spDefenseStat;
        int speed;
        void setPokemonMoveSet();
    public:
        Pokemon(std::string pkmnName, int lvl, bool isPlayerPkmn);

        // properties
        std::string name;
        bool isPlayerPokemon;
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
        std::vector<PokemonMove> getPokemonMoveSet();
};

#endif //POKEMON_H
