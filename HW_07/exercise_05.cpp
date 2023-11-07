#include <iostream>
#include <string>

void printAllSubstrings(const std::string &str) {
    std::string substring = "";
    for(size_t i = 0; i < str.size(); ++i) {
        for(size_t len = 1; len <= str.size() - i; ++len) {
            substring = str.substr(i, len);
            std::cout << substring << std::endl;
        }
    }
}

int main() {
    std::string word = "";

    std::cout << "Please enter a word: ";
    std::cin >> word;

    printAllSubstrings(word);

    return 0;
}