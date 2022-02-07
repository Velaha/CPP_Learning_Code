#include <iostream>
#include <string_view>

void print_in_console(std::string_view str) {
    std::cout << str << std::endl;
}

int main() {
    print_in_console("print me");

    // concaténation -> push_back, append, +=, +
    // extraction de sous-chaine -> substr
    // recherche de caractère ou de sous-chaine -> contains (, starts_with, ends_with), find family
    // comparaison -> compare, ==
    // remplacement d'une partie de la chaine -> replace

    // conversion de valeurs numériques en chaine de caratères -> to_string

    // conversion d'une chaine de caractères en valeur numérique -> sto.i / l(l) / ul(l) / f / (l)d
    // si la chaine ne contient pas vraiment de nombre alors le compilateur renvoie une
    // std::invalid_argument.

    return 0;
}
