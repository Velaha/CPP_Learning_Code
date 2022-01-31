#pragma once

#include "Animal.h"

#include <iostream>

class Cat : public Animal {
public:
    void sing(char separator) const override { std::cout << "Meow" << separator; }
};
