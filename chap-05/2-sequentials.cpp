#include <array>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

enum Fruit
{
    Apricot,
    Cherry,
    Mango,
    Raspberry,

    Fruit_Count,
};

void try_arrays() {
    // Implement array tests here.
    std::array<std::string, Fruit_Count> fruit_array;
    fruit_array[Apricot]   = "Apricot";
    fruit_array[Cherry]    = "Cherry";
    fruit_array[Mango]     = "Mango";
    fruit_array[Raspberry] = "Raspberry";
}

void try_lists() {
    std::list<int> l1 { 1, 2, 3 };
    std::list<int> l2(3, 4);
    std::list<int> l3;
    std::list<int> l4;

    l1.merge(l2);

    for (auto e : l1) {
        std::cout << e << std::endl;
    }
    std::cout << "-------------" << std::endl;

    l3.assign({ 5, 6, 7 });
    l4.emplace_back(8);
    l4.emplace_back(9);
    l4.emplace_back(10);
    l3.merge(l4);
    for (auto e : l3) {
        std::cout << e << std::endl;
    }
    std::cout << "-------------" << std::endl;

    auto middle = l1.begin();
    std::advance(middle, l1.size() / 2);

    l1.splice(middle, l3);
    for (auto e : l1) {
        std::cout << e << std::endl;
    }
}

void try_stacks() {
    // Implement stack tests here.

    // Le conteneur par défaut de std::stack est std::queue.
    // C'est ainsi car ce conteneur est performant dans l'ajout et le retrait d'élément de plus les itérateurs
    // ne sont jamais invalidés.

    std::stack<int, std::vector<int>> stack1;
    stack1.emplace(0);
    stack1.emplace(1);
    stack1.emplace(2);

    // ou
    // std::vector<int> v {0, 1, 2};
    // std::stack<int, std::vector<int>> stack1 { v };

    std::cout << "-------------" << std::endl;
    /*
    for (auto i = 0; i < stack1.size() - 1; i++) {
        std::cout << stack1[i] << std::endl;
    }*/
    // On ne peut pas procéder ainsi car la structure de donnée stack ne possède pas d'opérateur [].
    // On ne peut accéder qu'au premier élément.

    /*
    for (auto e : stack1) {
        std::cout << e << std::endl;
    }*/
    // On ne peut pas non plus accéder aux éléments d'une stack de cette manière car cette structure de
    // donnée n'implémente pas les fonctions begin et end.
}

int main() {
    try_arrays();
    try_lists();
    try_stacks();

    return 0;
}