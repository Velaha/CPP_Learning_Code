#include <iostream>
#include <memory>
#include <utility>

void display(const std::string& variable_name, const std::unique_ptr<int>& variable) {
    if (variable == nullptr) {
        std::cout << variable_name << " is empty" << std::endl;
    }
    else {
        std::cout << variable_name << " contains " << *variable << std::endl;
    }
}

std::unique_ptr<int> passthrough(std::unique_ptr<int> param) {
    auto locale = std::move(param);
    return locale;
}

int main() {
    std::unique_ptr<int> i1 = std::make_unique<int>(1);
    std::unique_ptr<int> i2 = std::make_unique<int>(2);

    display("i1", i1);
    display("i2", i2);

    i2 = passthrough(std::move(i1));

    display("i1", i1);
    display("i2", i2);

    return 0;
}