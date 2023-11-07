#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string s = "";

    std::cout << "Please enter a sentance: ";
    std::getline(std::cin, s);

    for(int i = 0; i < s.size(); i++) {
        if((isspace(s[i]) && isspace(s[i + 1]) || (isspace(s[i]) && isspace(s[i-1])))) {
            s.erase(s.begin() + i);
            i--;
        }
    }
    
    std::cout << s << std::endl;

    return 0;
}