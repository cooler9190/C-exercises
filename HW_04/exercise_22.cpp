#include <iostream>
#include <string>

void reverseString(std::string &s) {
    std::cout << "The sentance in reverse looks like this: " << std::endl;

    for(int i = s.size() - 1; i >= 0; i--) {
        std::cout << s[i];
    }
}

int main() {
    std::string s = " ";

    std::cout << "Please enter a sentance: ";
    getline(std::cin, s);

    reverseString(s);

    std::cout << s << std::endl;

    return 0;
}