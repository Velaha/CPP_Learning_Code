#pragma once

#include "Pokeball.h"

#include <array>
#include <string>

class PC;

// A person that capture Pokemons and make them fight.
class Trainer {
public:
    Trainer(std::string name, PC& pc)
        : _name { name }
        , _pc { pc } {}

    const std::string& name() const { return _name; }

    const std::array<Pokeball, 6>& pokeballs() const { return _pokeballs; }

private:
    std::string             _name;
    PC&                     _pc;
    std::array<Pokeball, 6> _pokeballs;
};
