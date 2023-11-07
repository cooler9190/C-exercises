#include <iostream>
#include <string>

int uniqueChar(std::string s) {
    int indexOfChar = -1;
    for(int i = 0; i < s.size(); i++) {
        if(isupper(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < s.size(); j++) {
            if((s[i] == s[j] && i != j) || (isspace(s[i]) || ispunct(s[i]))) {
                indexOfChar = -1;
                break;
            } else {
                indexOfChar = i;
            }
        }
        if(indexOfChar != -1) {
            break;
        }
    }

    if(indexOfChar == -1) {
        return s.size();
    } else {
        return indexOfChar;
    }
}

int main() {
    std::string s = " ";

    std::cout << "Please enter a word: ";
    getline(std::cin, s);

    std::cout << uniqueChar(s) << std::endl;

    return 0;
}