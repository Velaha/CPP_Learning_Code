#pragma once

#include "Car.h"

#include <iostream>

class FlyingCar : public Car {
public:
    FlyingCar(const Driver& driver, unsigned int speed)
        : Car { driver, speed }
        , _flyingSpeed { 10 * speed } {}

    unsigned int drive() const override {
        if (!_driver.has_flyingCar_licence()) {
            std::cerr << "No flying car licence detected..." << std::endl;
            return Car::drive();
        }
        std::cout << "Flying vrooooom!" << std::endl;
        return _flyingSpeed;
    }

private:
    unsigned int _flyingSpeed = 0;
};