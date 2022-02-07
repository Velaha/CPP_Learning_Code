#include "keys.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>

int main() {
    std::set<ComparableDog> comparableSet;

    ComparableDog foxy { "Foxy", "Berger Allemand" };
    comparableSet.emplace(foxy);
    // Pour l'instant impossible car ComparableDog n'implémente pas l'opérateur <
    ComparableDog jet { "Jetsan", "Lhassa Apso" };
    comparableSet.emplace(jet);

    std::cout << "Number of dogs : " << comparableSet.size() << std::endl;

    ComparableDog foxy2 = foxy;
    comparableSet.emplace(foxy2);
    std::cout << "Number of dogs : " << comparableSet.size() << std::endl;

    std::cout << "--------------" << std::endl;

    std::unordered_set<HashableDog> hashableUnorderedSet;
    // La classe HashableDog n'est pas encore hashable.

    HashableDog mavrik { "Mavrik", "Berger des Pyrenees" };
    hashableUnorderedSet.emplace(mavrik);
    HashableDog duchesse { "Duchesse", "Patou" };
    HashableDog navigue { "Navigue", "Colley" };

    hashableUnorderedSet.emplace(navigue);
    hashableUnorderedSet.emplace(duchesse);

    std::cout << "Number of dogs : " << hashableUnorderedSet.size() << std::endl;

    HashableDog mavrik2 = mavrik;
    hashableUnorderedSet.emplace(mavrik2);
    std::cout << "Number of dogs : " << hashableUnorderedSet.size() << std::endl;

    std::cout << "--------------" << std::endl;

    using Owner = std::pair<std::string, std::string>;

    std::map<ComparableDog, Owner> comparableMap;

    comparableMap.try_emplace(foxy, Owner { "Frederique", "Cottet" });
    comparableMap.emplace(ComparableDog { "Neo", "Whippet" }, Owner { "Marianne", "Orzakiewicz" });
    comparableMap.insert(std::make_pair(jet, Owner { "Andree", "Louis" }));
    comparableMap.insert_or_assign(ComparableDog { "Rosa", "Husky" }, Owner { "Charlotte", "Becquin" });

    comparableMap.emplace(foxy, Owner { "Vincent", "Heude" });            // ne fait rien
    comparableMap.insert_or_assign(jet, Owner { "Christophe", "Heude" }); // changement de proprio

    // Si on veut maintenant utiliser une unordered_map, il faut changer le type des clées par des
    // HashableDog.

    return 0;
}