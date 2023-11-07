#include <iostream>
#include <map>
#include <set>
#include <string>

class Phonebook {
    public:
    using PhoneNumber = std::string;
    using ContactName = std::string;

    void addContact(const ContactName &name, const PhoneNumber &number);

    PhoneNumber getNumber(const ContactName &name) const;

    void addContactToBlackList(const ContactName &name);

    void removeContactFromBlackList(const ContactName &name);

    void printContacts(const bool &ifBlackList = false);

    private:
    static const std::string MISSING_CONTACT_STR;

    using ContactsContainer = std::map<ContactName, PhoneNumber>;
    ContactsContainer m_contacts;

    using BlackList = std::set<PhoneNumber>;
    BlackList black_contacts;
};
