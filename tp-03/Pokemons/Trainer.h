#pragma once

#include <string>

class PC;

// A person that capture Pokemons and make them fight.
class Trainer {
public:
    Trainer(std::string name, PC& pc)
        : _name { name }
        , _pc { pc } {}

    std::string name() { return _name; }

private:
    std::string _name;
    PC&         _pc;
};
