#include <iostream>
#include <memory>
#include <utility>
#include <vector>

struct Test
{
    Test(int v)
        : value { v } {
        std::cout << "Constructor was called with " << v << "." << std::endl;
    }

    Test(const Test& other)
        : value { other.value } {
        std::cout << "Copy constructor was called." << std::endl;
    }

    int value = 0;
};

Test create_test(int value) {
    Test result { value };
    return result;
}

Test create_test_double(int value) {
    Test result = create_test(2 * value);
    return result;
}

std::unique_ptr<int> dynamic_add(int a, int b) {
    std::unique_ptr<int> result = std::make_unique<int>(a + b);
    return result;
}

int main() {
    Test test = create_test(3);
    std::cout << test.value << std::endl;

    Test test2 = create_test_double(3); // -> pas de copie non plus
    std::cout << test2.value << std::endl;

    Test test3 = Test { Test { Test { 3 } } }; // -> toujours aucune copie
    std::cout << test3.value << std::endl;

    std::unique_ptr<int> sum = dynamic_add(8, 12);
    std::cout << *sum << std::endl;

    std::cout << "---------------" << std::endl;

    /*FONCTIONNE PAS
    std::vector<std::unique_ptr<int>> many_ints;

    std::unique_ptr<int> value = std::make_unique<int>(3);
    many_ints.emplace_back(value); // -> tentative de copie*/

    /*std::vector<std::unique_ptr<int>> many_ints;
    many_ints.emplace_back(std::make_unique<int>(3)); // -> ok, mais ça fait beaucoup de parenthèses à lire...
    std::cout << *many_ints[0] << std::endl;

    std::unique_ptr<int> value = std::make_unique<int>(6);
    many_ints.emplace_back(std::move(value)); // -> ça fonctionne !
    std::cout << *many_ints[1] << std::endl;*/

    std::cout << "---------------" << std::endl;

    /*std::vector<std::unique_ptr<int>> many_ints;

    auto value = std::make_unique<int>(3);

    if (value != nullptr) {
        std::cout << "value is " << *value << std::endl;
    }
    else {
        std::cout << "value is empty" << std::endl;
    }

    many_ints.emplace_back(std::move(value));

    if (value != nullptr) {
        std::cout << "value is " << *value << std::endl;
    }
    else {
        std::cout << "value is empty" << std::endl;
    }

    if (many_ints[0] != nullptr) {
        std::cout << "many_ints[0] is " << *many_ints[0] << std::endl;
    }
    else {
        std::cout << "many_ints[0] is empty" << std::endl;
    }*/

    std::vector<std::string> many_ints;

    std::string value = "string";

    std::cout << "value is " << value << std::endl;

    many_ints.emplace_back(std::move(value));

    std::cout << "value is " << value << std::endl;

    std::cout << "many_ints[0] is " << many_ints[0] << std::endl;

    return 0;
}
