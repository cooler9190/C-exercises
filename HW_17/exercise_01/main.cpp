#include <iostream>
#include <string>
#include "Phonebook.hpp"


int main() {
    Phonebook phonebook;

    phonebook.addContact("Niki", "+3590808314");
    phonebook.addContact("Rado", "+3594408611");
    phonebook.addContact("Tosho", "+3590838915");
    phonebook.addContact("Gosho", "+3590807344");

    std::cout << phonebook.getNumber("Rado") << std::endl;

    phonebook.addContactToBlackList("Rado");

    std::cout << phonebook.getNumber("Rado") << std::endl;

    phonebook.removeContactFromBlackList("Rado");

    return 0;
}