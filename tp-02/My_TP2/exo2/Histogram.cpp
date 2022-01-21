#include <iostream>
#include <string>
#include <vector>

class Histogram {
public:
    // Question 2:
    // Maintenant qu'on a définit un constructeur de copie, il faut expliciter le constructeur par défaut pour
    // pouvoir compiler.
    Histogram() {}
    Histogram(const Histogram& other)
        : _count(other._count) {
        std::cout << "constructeur copie" << std::endl;
    }

    // analyse la string passée en paramètre
    void analyze(const std::string& entry) {
        for (int i = 97; i < 122; i++) {
            unsigned int nb = 0;
            for (char value : entry) {
                if (value == i) {
                    nb += 1;
                }
            }
            _count[i % 26] = nb;
        }
    }

    // affiche l'histogramme
    void print() const {
        for (int i = 97; i < 122; i++) {
            if (_count[i % 26] != 0) {
                std::cout << (char)(i) << " : " << _count[i % 26] << std::endl;
            }
        }
    }

private:
    // tableau contenant le nombre d'occurrences de chaque lettre entre 'a' et 'z'
    // Question 1:
    std::vector<unsigned int> _count { 26, 0 };
    // on ne peut pas initialiser avec = {26, 0} car ceci correspondrai à initialiser les deux premières
    // valeurs du tableau à 26 et 0.
};

int main(int argc, char const* argv[]) {
    // std::string entry;
    // Histogram   histo;

    // do {
    //     std::cin >> entry;
    //     histo.analyze(entry);
    //     histo.print();
    // }
    // while (entry != "QUIT");

    // Question 3:
    // Je suppose que le constructeur copie ne sera appelé qu'une seule fois
    Histogram h1, h2;
    Histogram h3 { Histogram { h1 } };
    // L'exécution le confirme
    return 0;
}
