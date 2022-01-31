#pragma once

#include "Animal.h"

#include <iostream>

class Cow : public Animal {
public:
    void sing(char separator) const override { std::cout << "Mewwwwwh" << separator; }
};
