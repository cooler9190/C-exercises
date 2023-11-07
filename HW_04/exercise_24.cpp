#include <iostream>
#include <string>

void replaceCharInString(std::string &s, char c1, char c2) {
    for(int i = 0; i < s.size(); i++) {
        if(c1 == toupper(c1)) {
            c1 = tolower(c1);
        } 
        if(c2 == toupper(c2)) {
            c2 = tolower(c2);
        }
        if(s[i] == toupper(s[i])) {
            s[i] = tolower(s[i]);
        }
        if(s[i] == c1) {
            s[i] = c2;
        }
    }
}

int main() {
    std::string str = "";
    char c1 = '0', c2 = '0';
    
    std::cout << "Please enter a sentance: ";
    getline(std::cin, str);

    std::cout << "Now enter the symbol you want to replace and the symbol you want to add: ";
    std::cin >> c1 >> c2;

    replaceCharInString(str, c1, c2);

    std::cout << "The symbol " << c1 << " was replaced with " << c2 << "and the resulting sentance is: "; 
    std::cout << str << std::endl;

    return 0;
}