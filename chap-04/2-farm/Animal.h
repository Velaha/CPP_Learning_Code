#pragma once

#include <iostream>

class Animal {
public:
    virtual ~Animal() {}

    virtual void sing(char separator) const { std::cout << "..." << separator; }
};
