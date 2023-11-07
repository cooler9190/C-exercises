#include <iostream>
#include <string>
#include "Phonebook.hpp"


int main() {
    bool blacklist = true;
    Phonebook phonebook;

    phonebook.addContact("Niki", "+3590808314");
    phonebook.addContact("Rado", "+3594408611");
    phonebook.addContact("Tosho", "+3590838915");
    phonebook.addContact("Gosho", "+3590807344");

    phonebook.printContacts();

    std::cout << phonebook.getNumber("Rado") << std::endl;

    phonebook.addContactToBlackList("Rado");
    phonebook.addContactToBlackList("Niki");

    std::cout << phonebook.getNumber("Rado") << std::endl;

    phonebook.removeContactFromBlackList("Rado");

    phonebook.printContacts(blacklist);

    Phonebook newPhonebook;

    newPhonebook.addContact("Niki", "+3590808314");
    newPhonebook.addContact("Rado", "+3594408611");
    newPhonebook.addContact("Tosho", "+4490838915");
    newPhonebook.addContact("Gosho", "+4490807344");

    newPhonebook.mergeTwoPhonebooks(phonebook, newPhonebook);

    newPhonebook.printContacts();

    return 0;
}