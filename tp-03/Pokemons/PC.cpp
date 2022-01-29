#include "PC.h"

/*Ecrire le code de give_back et inclure Trainer.h dans le fichier PC.cpp évite une dépendance circulaire.*/
#include "Trainer.h"

#include <iostream>

void PC::give_back(Trainer& trainer, const std::string& name) {
    for (auto index = _pokemons.begin(); index != _pokemons.end(); index++) {
        auto& poke = *index;
        if (poke->trainer() == &trainer && poke->name() == name) {
            trainer.capture(std::move(poke));
            _pokemons.erase(index);
            return;
        }
    }
}