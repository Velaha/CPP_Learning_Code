###
###

# Exercice 1

**1.Compilé, semi-compilé, interprété**  

compilé = plus rapide
semi-compilé = 
interprété = plus lent 

**2. Erreurs**  

Compilation -> au moment de la compilation du programme, erreur de syntaxe, corriger la syntaxe
Execution -> au moment de l'execution du programme, erreur de comportement (null pointer), catch les erreurs possibles

**3. UB**  

L'expression "undefined behavior" signifie qu'on a produit un code avec un comportement non conforme au standard. Il est possible de le compiler mais il y a de fortes chance qu'il ne donne pas le résultat attendu.

# Exercice 2

**1.**

(3) Les variables constantes doivent être initialisée.
(8) Impossible de convertir un int en bool.
(15) Impossible de convertir un const char vers un char.
(20) Reference non initialisé.
(24) Un const ne peut pas avoir d'adresse sinon il serai modifiable.
(25) Impossible d'avoir une reference de type int pour une variable de type bool.

**2.**

On ne peut pas donner la valeur de s0 car cette variable n'est pas initialisée.  
On ne peut pas non plus donner la valeur de ul7 car pour connaître sa valeur on a besoin de 
b3, or b3 n'est pas initialisable avec i1.  


# Exercice 3

**1.**
```
#include <iostream>

int add(const int& a, const int& b) {
    return a + b;
}

void add_to(int& a, const int& b) {
    a += b;
}

int main() {
    const int x { 10 };
    int       y = add(x, x);
    add_to(y, 22);
    std::cout << y << std::endl;
    return 0;
}
```  

**2. Paramètres par valeur, par référence et par référence constante**

par valeur = on ne donne que la valeur de l'argument et celui-ci ne sera pas modiifer par la fonction
par référence = on donne l'objet et donc ses valeurs et celui-ci sera modifiable par la fonction
par référence constante = on donne l'objet donc on aura accès à ses valeurs mais on ne pourra pas le modifier.

Préférable de passer par valeur si objet simple (int, char, ...)
                     par référence si objet compliqué (vector)
                     par référence constante si objet compliqué qu'on ne veut pas modifier (vector)

**3. **
