#include <iostream>
#include <string>

void stringToObject(std::string &str) {
    std::cout << "Please enter a text: ";
    getline(std::cin, str);
}

int main() {
    std::string string = " ";

    stringToObject(string);

    std::cout << "The input you entered is: " << std::endl;
    std::cout << string << std::endl;

    return 0;
}