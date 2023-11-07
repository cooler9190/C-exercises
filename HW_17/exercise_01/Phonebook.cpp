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