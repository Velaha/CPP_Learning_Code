int main() {
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

    return 0;
}