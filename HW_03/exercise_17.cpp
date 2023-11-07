#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
    std::string s = "";
    char c = '0';
    std::vector <int> v;

    std::cout << "Please enter a word and a letter to be searched: ";
    std::cin >> s >> c;

    for(int i = 0; i < s.size(); i++) {
        if(c == toupper(c)) {
            c = tolower(c);
        }
        if(s[i] == toupper(s[i])) {
            s[i] = tolower(s[i]);
        }
        if(c == s[i]) {
            v.push_back(i);
        }
    }

    if(v.size() == 0) {
        std::cout << "The word " << s << " does not contain the letter " << c << std::endl;
    } else if(v.size() == 1) {
        std::cout << "The word " << s << " contains only one instance of " << c << " at index " << v[0] << std::endl;
    } else {
        std::cout << "The first and last instance of " << c << " are at index " << v[0] << " and " << v[v.size() - 1] << std::endl; 
    }

    return 0;
}