#pragma once

#include <string>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon {
public:
    Pokemon(std::string name)
        : _name { name } {}
    Pokemon() {}

    const std::string& name() const { return _name; }

    const Trainer* trainer() const { return _trainer; }

    void setTrainer(const Trainer& trainer) { _trainer = &trainer; }

private:
    std::string    _name;
    const Trainer* _trainer = nullptr;
};
