#pragma once

#include "Animal.h"
#include "Cat.h"
#include "Chicken.h"
#include "Cow.h"
#include "Dog.h"

#include <iostream>
#include <memory>
#include <vector>

class Opera {
public:
    Opera() {
        _animals.emplace_back(std::make_unique<Cat>());
        _animals.emplace_back(std::make_unique<Chicken>());
        _animals.emplace_back(std::make_unique<Cow>());
        _animals.emplace_back(std::make_unique<Dog>());
    }

    void sing(char separator) const {
        for (const auto& animal : _animals) {
            animal->sing(separator);
        }
        std::cout << std::endl;
    }

private:
    std::vector<std::unique_ptr<Animal>> _animals;
};