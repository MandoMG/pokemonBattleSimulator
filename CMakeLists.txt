cmake_minimum_required(VERSION 3.29)
project(pokemonBattleSimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(pokemonBattleSimulator main.cpp
        Pokemon.cpp
        Pokemon.h
        PokemonMove.h
        PokemonMove.cpp
        types/Enums.h)
