#pragma once

#include "Pokemon.h"

#include <memory>
#include <utility>

// A ball where Pokemon sleep.
class Pokeball {
public:
    bool empty() { return _empty; }

    void store(std::unique_ptr<Pokemon> pokemon) {
        _pokemon = std::move(pokemon);
        _empty   = false;
    }

    Pokemon& pokemon() { return *_pokemon; }

private:
    bool                     _empty = true;
    std::unique_ptr<Pokemon> _pokemon;
};