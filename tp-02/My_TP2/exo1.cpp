#include <iostream>

struct AddX
{
    static int global_sum;
    const int  _x;

    AddX(const int x)
        : _x { x } {}

    void apply() const { global_sum += _x; }
};

int AddX::global_sum = 0; // initialisation

int main() {
    AddX add10 { 10 }, add5 { 5 };
    add10.apply();
    add5.apply();

    AddX add1 { 1 };
    add1.apply();
    add1.apply();

    std::cout << add5.global_sum << std::endl << add1.global_sum << std::endl;
    return 0;
}

/*
 * 1. Le code affiche
  17
  17

  * 2. Si on enlève la ligne marquée initialisation alors le programme ne compile plus.
*/