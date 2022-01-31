#include "Car.h"
#include "FlyingCar.h"
#include "Scooter.h"
#include "Vehicle.h"

#include <iostream>

int main() {
    Driver     car_driver;
    Car        car { car_driver, 60u };
    const auto distance_in_car = car.drive();
    std::cout << distance_in_car << " km in a car." << std::endl;

    Driver     mini_gangster;
    Scooter    scooter { mini_gangster, 180u };
    const auto distance_in_scooter = scooter.drive();
    std::cout << distance_in_scooter << " km with a scooter." << std::endl;

    std::cout << "-------------" << std::endl;

    Driver    flying_driver;
    FlyingCar flying_car { flying_driver, 60u };

    auto distance_in_flying_car = flying_car.drive();
    std::cout << distance_in_flying_car << " km with a flying car." << std::endl;

    flying_driver.pass_car_licence_exam();
    distance_in_flying_car = flying_car.drive();
    std::cout << distance_in_flying_car << " km with a flying car." << std::endl;

    flying_driver.pass_flyingCar_licence_exam();
    distance_in_flying_car = flying_car.drive();
    std::cout << distance_in_flying_car << " km with a flying car." << std::endl;

    // Vehicle vehicle { car_driver };

    return 0;
}