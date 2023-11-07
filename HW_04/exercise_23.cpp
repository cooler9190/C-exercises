#include <iostream>
#include <string>

int numberOfOccurences(std::string s, char c) {
    int count = 0;
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

    return count;
}

int main() {
    std::string s = "";
    char c = '0';
    
    std::cout << "Please enter a sentance: ";
    getline(std::cin, s);

    std::cout << "Now enter the letter to be searched: ";
    std::cin >> c;

    std::cout << "The letter " << c << " can be found " << numberOfOccurences(s,c) << " time/s" << std::endl;

    return 0;
}