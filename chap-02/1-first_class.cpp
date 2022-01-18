#include <iostream>
#include <string>

class Person {
private:
    std::string _name;
    // On peut mettre int, mais unsigned int limite les erreurs potentielles en autorisant uniquement les
    // entiers positifs. (0u est l'équivalent de 0 en unsigned int, à utiliser avec auto essentiellement)
    unsigned int _age = 0;

public:
    void              set_name(const std::string& name) { _name = name; }
    void              set_age(unsigned int age) { _age = age; }
    const std::string get_name() const { return _name; }
    unsigned int      get_age() const { return _age; }
};

int main() {
    Person p;

    p.set_name("Batman");

    p.set_age(23);

    std::cout << "Person named '" << p.get_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}
