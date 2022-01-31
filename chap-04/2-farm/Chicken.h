#pragma once

#include "Animal.h"

#include <iostream>

class Chicken : public Animal {
public:
    ~Chicken() override { std::cout << "CotCooooooooot!" << std::endl; }
    void sing(char separator) const override { std::cout << "Cotcotcotcodet" << separator; }
};
