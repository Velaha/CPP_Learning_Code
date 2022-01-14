#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned int> count_lower(const std::string& entry) {
    std::vector<unsigned int> array;

    for (int i = 97; i < 122; i++) {
        unsigned int nb = 0;
        for (char value : entry) {
            if (value == i) {
                nb += 1;
            }
        }
        array.emplace_back(nb);
    }

    return array;
}

void display_lower_occ(const std::vector<unsigned int>& array) {
    for (unsigned int i = 0; i < array.size(); i++) {
        if (array[i] != 0) {
            std::cout << (char)(i + 97) << " : " << array[i] << std::endl;
        }
    }
}

int main(int argc, char const* argv[]) {
    std::string entry;
    std::string old_entries;

    do {
        std::cin >> entry;
        old_entries.append(entry);
        auto array = count_lower(entry);
        display_lower_occ(array);
        std::cout << old_entries << std::endl;
    }
    while (entry != "QUIT");

    return 0;
}
