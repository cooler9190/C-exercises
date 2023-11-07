#include <iostream>
#include <string>

int main() {
    std::string s = "";
    char c = '0';
    int count = 0;

    std::cout << "Please enter a word and a letter to be searched: ";
    std::cin >> s >> c;

    for(int i = 0; i < s.size(); i++) {
        if(c == toupper(c)) {
            c = tolower(c);
        }
        if(s[i] == toupper(s[i])) {
            s[i] = tolower(s[i]);
        }
        if(s[i] == c) {
            count++;
        }
    }

    std::cout << "The letter " << c << " can be found " << count << " time/s" << std::endl;

    return 0;
}