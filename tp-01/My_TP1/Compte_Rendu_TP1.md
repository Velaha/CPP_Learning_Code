# Compte Rendu - TP1

## Exercice 1

**1. Compilé, semi-compilé, interprété**  

Langage compilé (C) :  
* Avantage : performant  
* Inconvénient : nécessité de recompiler à chaque modification et à chaque changement de système (exécutables non portables)  

Langage semi-compilé (Java) :  
* Avantage : conserve les performances des langage compilés  
* Inconvénient : nécessite un interpréteur 

Langage interprété (Python) :  
* Avantage : les exécutables sont portables sur différents systèmes 
* Inconvénient : plut lent et nécessite un interpréteur

**2. Erreurs**  

Erreur de compilation :  
* Apparition : Au moment de la compilation du programme
* Raison : Erreur de syntaxe
* Solution : Corriger la syntaxe
Erreur à l'exécution :  
* Apparition : Au moment de l'exécution du programme
* Raison : Erreur dans le comportement du programme (null pointer)
* Solution : Faire attention à ses erreurs (conditions, ...)

**3. UB**  

L'expression "undefined behavior" signifie qu'on a produit un code avec un comportement non conforme au standard. Il est possible de le compiler mais il y a de fortes chance qu'il ne donne pas le résultat attendu.

## Exercice 2

**1. Erreurs avec et sans -Werror**  

(3) Les variables constantes doivent être initialisées.  
(8) Impossible de convertir un int en bool.  
(15) Impossible de convertir un const char vers un char.  
(20) Référence non initialisé.  
(24) Une variable constante ne peut pas avoir d'adresse sinon elle serai modifiable.  
(25) Impossible d'avoir une référence de type int pour une variable de type bool.  

**2. Valeurs de s0 et ul7**  

On ne peut pas donner la valeur de s0 car cette variable n'est pas initialisée.  
On ne peut pas non plus donner la valeur de ul7 car pour connaître sa valeur on a besoin de 
b3, or b3 n'est pas initialisable avec i1.  


## Exercice 3

**2. Paramètres par valeur, par référence et par référence constante**

Par valeur, on ne donne que la valeur de l'argument et celui-ci ne pourra pas être modifier par la fonction.  
Par référence, on donne l'objet et donc ses valeurs et celui-ci sera modifiable par la fonction.  
Par référence constante, on fournit l'objet et ses valeurs mais on ne pourra pas le modifier.  

Il est préférable de passer un argument par valeur si l'objet est simple (int, char, ...).  
On utilise plutôt le passage par référence si l'objet est plus compliqué et donc plus lourd en mémoire (vector).
Le passage par référence constante est utilisé dans le même cas qu'énoncé ci-dessus mais qu'on ne veut pas modifier l'objet.  
