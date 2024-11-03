# Pokemon Battle Simulator

A personal project built to learn C++ through the classic mechanics of Pokémon battles. This simulator emulates battles between selected Pokémon, each with distinct moves and abilities, drawing inspiration from the mechanics of Generation I & II Pokémon games.

## Features

* Turn-based combat: Emulates the same turn based combat from the original games with health points, attack power, defense and speed.
* Move Selection: Allows you to pick from a variety of moves, each one with unique effects on HP, accuracy, etc. and considering type advantages
* Type Matchup: Considers type effectivenes to enhance battle strategy (e.g., Fire > Grass)
* Dynamic Stats Calculation: Calculates damage based on type, attack, and defense stats for a realistic battle experience.
* ... and more features to come.

## Order of Turns

1. Both Pokemons Select a move
2. Move priority is determined. If there is a move that takes higher priority, Pokemon speed is ignored and the Pokemon with a higher priority move attacks first
3. If priority of both Pokemon moves is the same, the pokemon with higher speed stat attacks first. If speed stat is the same, it uses chance to determine who goes first.

## Build With

* C++
