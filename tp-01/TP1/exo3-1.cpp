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