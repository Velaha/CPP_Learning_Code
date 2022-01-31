#pragma once

#include "Animal.h"

#include <iostream>

class Dog : public Animal {
public:
    void sing(char separator) const override { std::cout << "Waf" << separator; }
};
