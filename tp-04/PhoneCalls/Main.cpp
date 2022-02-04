#include "HomePhone.h"
#include "MobilePhone.h"
#include "Person.h"
#include "Phone.h"

int main() {
    std::cout << "--------1---------" << std::endl;
    Person paul { "Paul", 3 };
    // Phone  phone { paul };
    // phone.ring();

    // 1. La différence entre const Person et const Person& est que le premier est un objet Person constant
    // alors
    //  que l'autre est une référence constante à un objet Person.
    // Stocker un attribut par référence permet de ne pas réallouer un objet déjà créer.
    paul.set_position(8);
    // Après cette instruction, phone._owner aura pour position 8.
    paul.set_position(3);

    std::cout << "--------2---------" << std::endl;

    // 2.
    HomePhone homephone { paul };
    homephone.ring();

    std::cout << "--------3---------" << std::endl;

    // 3.
    HomePhone close_phone { paul, 3 };
    close_phone.ring(); // Hi! Paul on the phone.

    HomePhone far_phone { paul, -10 };
    far_phone.ring();

    std::cout << "--------4---------" << std::endl;

    // 4.
    const Phone& normal_phone = far_phone;
    normal_phone.ring(); // This is the voicemail of Paul. Please leave a message.

    std::cout << "--------5---------" << std::endl;

    // 5. Le terme pour ce genre d'appel est un appel virtuel.
    //  Les classes sur lesquelles on peut faire cet appel sont des classes polymorphes
    //  Lorsqu'on définit ce type de classe il faut toujours rendre le destructeur virtuel.

    std::cout << "--------6---------" << std::endl;

    MobilePhone mobile_phone { paul };

    const Phone& normal_phone2 = mobile_phone;
    normal_phone2.ring(); // Hi! Paul on the phone.

    std::cout << "--------7---------" << std::endl;

    // 7. On met le constructeur de Phone dans la partie protected, ce qui en fait une classe abstraite.

    // Phone normal_phone { paul }; // Doesn't compile!

    std::cout << "--------8---------" << std::endl;

    // 8. Le code suivant compile et c'est normal.
    //  Cela s'explique par le fait qu'on construit l'objet Phone grâce à une de ses classes-fille.

    HomePhone far_phone2 { paul, -10 };

    // const Phone normal_phone3 = far_phone2;
    // normal_phone3.ring();

    std::cout << "--------9---------" << std::endl;

    // 9. En C++, pour qu'une classe ne soit plus instantiable du tout il faut lui ajouter une fonction
    // virtuelle pure.
    // Ce type de classe est appelée classe polymorphe.

    std::cout << "--------10--------" << std::endl;

    // 10. Le code n'aurai pas compilé si on n'avait pas implémenté la fonction membre ring() dans
    // MobilePhone.

    MobilePhone mobile_phone2 { paul };

    return 0;
}
