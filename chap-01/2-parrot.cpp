// Implement the program here.

#include <iostream>
#include <string>
/*AfterControlStatement: Always -> false*/

int main() {
    using namespace std;
    // int number = 0;

    /*
    while (true) {
        std::cin >> number;

        if (number == -1) {
            break;
        }

        std::cout << "Parrot says " << number << " !" << std::endl;
    }
    */
    /*
    do {
        std::cin >> number;
        std::cout << "Parrot says " << number << " !" << std::endl;
    }
    while (number != -1);
    */

    string word;

    for (int i = 0; i < 10; i++) {
        cin >> word;
        cout << "Parrot says " << word << " !" << endl;
    }

    return 0;
}
