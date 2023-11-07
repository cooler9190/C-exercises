#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s = "";
    
    std::cout << "Please enter a word: ";
    std::cin >> s;
    
    for(int i = 0; i < s.size(); i++) {
        if(islower(s[i])) {
            s[i] = toupper(s[i]);
        }
        if(s[i] == '.') {
            s[i] = '!';
            s.insert(i, "!!");
        }
    }

    std::cout << s << std::endl;

    return 0;
}

