#include "Phonebook.hpp"

const std::string Phonebook::MISSING_CONTACT_STR = "missing";

void Phonebook::addContact(const ContactName &name, const PhoneNumber &number) {
    m_contacts[name] = number;
}

Phonebook::PhoneNumber Phonebook::getNumber(const ContactName &name) const {
    auto it = m_contacts.find(name);
    return it == m_contacts.end() ? MISSING_CONTACT_STR : it->second;
}

void Phonebook::addContactToBlackList(const ContactName &name) {
    black_contacts.insert(name);
    m_contacts.erase(name);
}

void Phonebook::removeContactFromBlackList(const ContactName &name) {
    auto it = black_contacts.find(name);
    black_contacts.erase(it);
}

void Phonebook::printContacts(const bool &ifBlackList) {
    if(ifBlackList == false) {
        std::cout << "Phonebook contacts: " << std::endl;
        for(auto iter = m_contacts.begin(); iter != m_contacts.end(); ++iter) {
            std::cout << iter->first << ": ";
            std::cout << iter->second << std::endl;
        }

        std::cout << std::endl;
    } else {
        std::cout << "Phonebook contacts: " << std::endl;
        for(auto iter = m_contacts.begin(); iter != m_contacts.end(); ++iter) {
            std::cout << iter->first << ": ";
            std::cout << iter->second << std::endl;
        }

        std::cout << std::endl;

        std::cout << "Blacklisted contacts: " << std::endl;
        for(auto iter = black_contacts.begin(); iter != black_contacts.end(); ++iter) {
            std::cout << *iter << std::endl;
        }
    }
}

void Phonebook::mergeTwoPhonebooks(const Phonebook &first, Phonebook &second) {
    second.m_contacts.insert(first.m_contacts.begin(), first.m_contacts.end());
}