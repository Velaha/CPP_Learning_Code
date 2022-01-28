#pragma once

#include "Pokemon.h"

#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC {
public:
    std::vector<Pokemon> pokemons() { return _pokemons; }

private:
    std::vector<Pokemon> _pokemons;
    bool                 _empty = true;
};
