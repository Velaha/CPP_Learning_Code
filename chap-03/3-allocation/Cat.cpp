#include "Cat.h"

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<Cat> cat = std::make_unique<Cat>("Chat");
    std::cout << *cat << std::endl;

    std::unique_ptr<Cat> cat2;
    if (cat2 == nullptr) {
        std::cout << "nullptr ok " << std::endl;
    }

    cat2 = std::make_unique<Cat>("Chat2");

    std::cout << "cat == cat2 : " << (cat == cat2) << std::endl;
    std::cout << "*cat == *cat2 : " << (*cat == *cat2) << std::endl;

    cat.reset();

    if (cat == nullptr) {
        std::cout << "nullptr ok " << std::endl;
    }

    return 0;
}