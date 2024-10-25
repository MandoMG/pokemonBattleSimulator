#include <iostream>
#include "Pokemon.h"
using namespace std;

int main() {
    cout << "Welcome to Pokemon Battle Simulator!" << endl;
    Pokemon pokemon("Charmander", 6);
    pokemon.displayInfo();

    // Add Pokemon Selection
    // Add Pokemon Attacks
    // Determine turns
    return 0;
}

void performAttack(Pokemon attackingPokemon, Pokemon defenderPokemon) {
    // make the following variables dynamic
    int basePower = 100; // movement base power
    bool isSpecialAttack = false; // depends from special attack or regular
    int pokemonAttackStat = isSpecialAttack ? 100 : 150; // get pokemon atk stat or special atk stat
    int pokemonDefenseStat  = isSpecialAttack ? 100 : 150; // get pokemon def stat or special def stat
    int modifier = 1; // get modifier from type comparison (i.e., fire vs water, etc.)

    const int baseDamage = (((2 * attackingPokemon.level) / 5) + 2);
    const int attackOverDefense = (pokemonAttackStat/pokemonDefenseStat);
    const int modifierRate = (modifier / 50);
    const int damage = baseDamage * basePower * attackOverDefense * modifierRate + 2;

    defenderPokemon.setDamageReceived(damage);
    defenderPokemon.displayHealthPoints();
}
