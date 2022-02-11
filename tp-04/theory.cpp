#include <iostream>

class TestStatic {
public:
    // virtual static void test() {}

private:
    /* data */
};

class A {
    int          x;
    virtual void some_function() {}
};

class B {
    int  x;
    void some_function() {}
};

int main(void) {
    // 1. Avant de tester :
    // A mon avis, il n'est pas possible qu'une fonction virtuelle puisse être statique.
    // En effet, un membre static est indépendant du reste de la classe. Il me parait donc difficile
    // d'imaginer qu'une fonction virtuelle puisse être statique car celle-ci devra forcément être implémentée
    // au moment de l'héritage : ce qui implique de ne pas être indépendant du reste de la classe.
    //
    // Après avoir testé :
    // Une fonction virtuelle ne peut effectivement pas être statique.

    // 2.
    std::cout << "Sizeof(class A) : " << sizeof(A) << std::endl;
    std::cout << "Sizeof(class B) : " << sizeof(B) << std::endl;

    // On remarque que la classe A prend 4 fois plus de place en  mémoire que la classe B.
    // Etant donné que la seule différence entre la classe A et la classe B est le mot-clé 'virtual' devant la
    // fonction membre 'some_function', on peut en conclure que déclarer une fonction comme virtuelle prend
    // plus de place en mémoire.
    // En effet, les fonctions virtuelles nécessite la création d'une virtual table. C'est surement
    // l'existence de cette table qui rend la classe A plus volumineuse.

    // 3. [ Bonus ]
    // Un upcast correspond à caster une classe fille dans le type de la classe mère.
    // Un downcast correspond à caster une classe mère dans le type d'une de ses classes filles.
    //
    // Ce dernier peut poser problème car la classe fille peut implémenter de nouvelles fonctions et posséder
    // de nouveaux champs que la classe mère ne possèdent pas et ne pourra donc pas utiliser.
    // En pratique, on évite de faire ce genre de cast mais pour s'en méfier on utilise des casts explicites.
    //
    // Un 'static_cast' et un 'dynamic_cast' permettent tout deux d'effectuer des casts.
    // La différence principale est que le 'dynamic_cast' permet de convertir en toute sécurité puisqu'il
    // renvoie soit un objet du type dans lequel on souhaitait caster, si les deux classes sont compatibles,
    // soit un nullptr.

    return 0;
}
