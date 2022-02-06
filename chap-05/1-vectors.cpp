
// La complexite d'insertion dans une std::map est logarithmique.

// Dans la classe std::vector, push_back permet d'ajouter un élément à la fin de la liste mais sans le
// créer, il s'agit d'une copie ou d'un déplacement. Alors que emplace_back permet d'ajouter un élément en
// fin de liste en le créant.

// La fonction qui permet de savoir si un conteneur est vide est empty().

// std::vector::size() permet de connaitre la taille courante du vecteur, soit le nombre d'élément qu'il
// contient.
// std::vector::capacity() permet de connaitre sa capacité maximum, soit la taille qu'il peut
// atteindre avant de devoir réallouer de la mémoire.

// La classe std::stack sert à simuler une structure LIFO (Last In First Out).

// Il n'existe pas de fonction qui permet de retirer son dernier élément à une std::queue.

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::vector<int> vec1 { 4, 0 }; // initialisation avec une liste -> surcharge n°10

    for (auto i : vec1) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    std::vector<int> vec2(4, 0); // initialisation avec un compteur de copie et une valeur -> surcharge n°3

    for (auto i : vec2) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    int              array[] = { 0, 1, 2, 3, 4, 5 };
    int*             first   = &array[0]; // array
    int*             last    = &array[6]; // array + 6
    std::vector<int> vec3(first, last);

    for (auto i : vec3) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    for (int from_left = 0, from_right = vec3.size() - 1; from_left < from_right; from_left++, from_right--) {
        std::swap(vec3[from_left], vec3[from_right]);
    }

    for (auto i : vec3) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    // insert et emplace permettent d'ajouter un élément dans un vecteur.
    // Le premier ajoute un élément sans le créer, il fait plutôt une copie ou un déplacement et le second
    // créer l'élément avant de l'ajouter à la liste.

    std::vector vec4 { 1, 2, 3 };

    for (auto it = vec4.begin(); it < vec4.end(); it += 2) {
        it = vec4.emplace(it, *it);
    }

    for (auto i : vec4) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    // pop_back permet de supprimer le dernier élément d'un vecteur.

    while (!vec4.empty()) {
        vec4.pop_back();
    }

    std::cout << "empty vec4 : " << vec4.empty() << std::endl;

    std::cout << "-----------------" << std::endl;

    // Il faut utiliser une iterateur pour donner l'élément à effacer à erase.

    std::vector<int> vec5 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    vec5.erase(vec5.begin() + 2, vec5.begin() + 7);

    for (auto i : vec5) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    std::vector v { 1, 2, 3, 9, 6 };

    auto it = std::find(v.begin(), v.end(), 9);

    if (it != v.end()) {
        v.erase(it);
    }

    for (auto i : v) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    v.assign(5, 2);
    for (auto i : v) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    std::vector<int> vec6 = { 0, 2, 32, -4, 3 };

    v.assign(vec6.begin(), vec6.end()); // ou v.assign({ 0, 2, 32, -4, 3 });
    for (auto i : v) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    v.clear();
    for (auto i : v) {
        std::cout << i << std::endl;
    }
    std::cout << "empty v : " << v.empty() << std::endl;

    return 0;
}