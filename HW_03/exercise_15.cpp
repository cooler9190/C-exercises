#include <iostream>
#include <string>

int main() {
    std::string s = "";
    
    std::cout << "Plese enter a word: ";
    std::cin >> s;

    for(unsigned int i = s.size(); i != 0 - 1; i--) {
        std::cout << s[i];
    }

    std::cout << std::endl;
    return 0;
}