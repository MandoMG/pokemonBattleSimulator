#include <iostream>
#include "Pokemon.h"
using namespace std;

int getSelectionIndex(Pokemon *attackingPokemon)
{
    if (attackingPokemon->isPlayerPokemon) {
        int selectionIndex;

        int size = attackingPokemon->getPokemonMoveSet().size();
        for (int i = 0; i < size; i++) {
            cout << i << ": " << attackingPokemon->getPokemonMoveSet()[i].getName() << endl;
        }

        cout << "Select the index of the selected move: ";
        cin >> selectionIndex;

        return selectionIndex;
    }

    return std::rand() % 3; // used to determine move
}

PokemonMove selectMove(Pokemon *playerPokemon)
{
    if (const int selectionIndex = getSelectionIndex(playerPokemon); selectionIndex > 0 && selectionIndex<playerPokemon->getPokemonMoveSet().size()) {
        return playerPokemon->getPokemonMoveSet()[selectionIndex];
    }

    return playerPokemon->getPokemonMoveSet()[0];
}

void performAttack(Pokemon *attackingPokemon, Pokemon *defenderPokemon)
{
    if (attackingPokemon->getHealthPoints() == 0 || defenderPokemon->getHealthPoints() == 0) {
        return;
    }

    PokemonMove selectedMove = selectMove(attackingPokemon);
    cout << attackingPokemon->name << " used " << selectedMove.getName() << endl;

    // TODO: if is status, add logic to affect status of defending pokemon
    if(selectedMove.isStatus()) {
        cout << "Should affect only status of pokemon!" << endl;
        return;
    }

    // make the following variables dynamic
    int basePower = selectedMove.getBasePower();
    bool isSpecialAttack = selectedMove.isSpecial();
    int pokemonAttackStat = attackingPokemon->getAttackStat(isSpecialAttack);
    int pokemonDefenseStat = defenderPokemon->getDefenseStat(isSpecialAttack);
    double modifier = 1.0; // get modifier from type comparison (i.e., fire vs water, etc.)

    const int baseDamage = (((2 * attackingPokemon->level) / 5) + 2);
    const int attackOverDefense = (pokemonAttackStat / pokemonDefenseStat);
    const double modifierRate = (modifier / 50);
    const int damage = baseDamage * basePower * attackOverDefense * modifierRate + 2;

    defenderPokemon->setDamageReceived(damage);
    defenderPokemon->displayHealthPoints();
}

void performTurn(Pokemon *playerPokemon, Pokemon *enemyPokemon)
{
    // TODO: Change move selection to happen before performing attack, this will determine if the move has a priority
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
    Pokemon charmander("Charmander", 6, true);
    charmander.displayInfo();
    Pokemon *charmanderPtr = &charmander;

    Pokemon pikachu("Pikachu", 5, false);
    pikachu.displayInfo();
    Pokemon *pikachuPtr = &pikachu;

    // Add Pokemon Selection

    // Add Pokemon Attacks
    while (charmanderPtr->getHealthPoints() != 0 || charmanderPtr->getHealthPoints() != 0) {
        performTurn(charmanderPtr, pikachuPtr); // Determines turns and performs attack
    }
    return 0;
}
