#pragma once

#include <iostream>

class Driver {
public:
    bool has_car_licence() const { return _licence; }
    void pass_car_licence_exam() { _licence = true; }

    bool has_flyingCar_licence() const { return _flyingLicence; }
    void pass_flyingCar_licence_exam() { _flyingLicence = true; }

private:
    bool _licence       = false;
    bool _flyingLicence = false;
};

class Vehicle {
    // protected:
    //     Vehicle(const Driver& driver)
    //         : _driver { driver } {}
public:
    Vehicle(const Driver& driver)
        : _driver { driver } {}

    virtual ~Vehicle() {}

    // virtual unsigned int drive() const {
    //     std::cerr << "Not implemented" << std::endl;
    //     return 0u;
    // }
    virtual unsigned int drive() const = 0;

protected:
    const Driver& _driver;
};
