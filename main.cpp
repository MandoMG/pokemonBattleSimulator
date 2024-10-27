#include <iostream>
#include "Pokemon.h"
using namespace std;

void performAttack(Pokemon* attackingPokemon, Pokemon* defenderPokemon)
{
    if(attackingPokemon->getHealthPoints() == 0 || defenderPokemon->getHealthPoints() == 0) {
        return;
    }

    // make the following variables dynamic
    int basePower = 100; // movement base power
    bool isSpecialAttack = false; // depends from special attack or regular
    int pokemonAttackStat = attackingPokemon->getAttackStat(isSpecialAttack);
    int pokemonDefenseStat  = defenderPokemon->getDefenseStat(isSpecialAttack);
    int modifier = 1; // get modifier from type comparison (i.e., fire vs water, etc.)

    const int baseDamage = (((2 * attackingPokemon->level) / 5) + 2);
    const int attackOverDefense = (pokemonAttackStat/pokemonDefenseStat);
    const int modifierRate = (modifier / 50);
    const int damage = baseDamage * basePower * attackOverDefense * modifierRate + 2;

    defenderPokemon->setDamageReceived(damage);
    defenderPokemon->displayHealthPoints();
}

void attackStep(Pokemon* playerPokemon, Pokemon* enemyPokemon)
{
    if (playerPokemon->getSpeedStat() > enemyPokemon->getSpeedStat()) {
        performAttack(playerPokemon, enemyPokemon);
        performAttack(enemyPokemon, playerPokemon);
    } else if (enemyPokemon->getSpeedStat() > playerPokemon->getSpeedStat()) {
        performAttack(enemyPokemon, playerPokemon);
        performAttack(playerPokemon, enemyPokemon);
    } else {
        // speed is same
        int randomNum = std::rand() % 100; // used to determine chance
        if (randomNum < 50) {
            performAttack(playerPokemon, enemyPokemon);
            performAttack(enemyPokemon, playerPokemon);
        } else {
            performAttack(enemyPokemon, playerPokemon);
            performAttack(playerPokemon, enemyPokemon);
        }
    }
}

int main()
{
    std::srand(std::time(nullptr));
    cout << "Welcome to Pokemon Battle Simulator!" << endl;
    Pokemon charmander("Charmander", 6);
    charmander.displayInfo();
    Pokemon* charmanderPtr = &charmander;

    Pokemon caterpie("Caterpie", 5);
    caterpie.displayInfo();
    Pokemon* caterpiePtr = &caterpie;

    // Add Pokemon Selection
    // Add Attack Selection
    // Add Pokemon Attacks
    while (charmanderPtr->getHealthPoints() != 0 || charmanderPtr->getHealthPoints() != 0) {
        // Determines turns and performs attack
        attackStep(charmanderPtr, caterpiePtr);
    }
    return 0;
}
