#pragma once

#include "Pokemon.h"

#include <memory>
#include <utility>

// A ball where Pokemon sleep.
class Pokeball {
public:
    /*devant : bool
    fin : fonction qui ne modifie pas l'objet*/
    bool empty() const { return _pokemon == nullptr; }

    void store(std::unique_ptr<Pokemon> pokemon) { _pokemon = std::move(pokemon); }

    Pokemon& pokemon() const { return *_pokemon; }

private:
    std::unique_ptr<Pokemon> _pokemon;
};