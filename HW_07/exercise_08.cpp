#include <iostream>
#include <string>

using string = std::string;

bool areAnagrams(string &string1, string &string2) {
    bool flag = false;
    int count = 0;
    if(string1.size() == string2.size()) {
        flag = true;
    } else {
        return false;
    }

    for(size_t i = 0; i < string1.size(); ++i) {
        if(isupper(string1[i])) {
            string1[i] = tolower(string1[i]);
        }

        if(isupper(string2[i])) {
            string2[i] = tolower(string2[i]);
        }
    }

    for(size_t i = 0; i < string1.size(); ++i) {
        for(size_t j = 0; j <string2.size(); ++j) {
            if(string1[i] == string2[j]) {
                ++count;
                break;
            }
        }
    }

    if(count == string1.size() && flag == true) {
        return true;
    }

    return false;
}

int main() {
    string word1 = "", word2 = "";

    std::cout << "Please enter first string: ";
    std::getline(std::cin, word1);

    std::cout << "Please enter second string: ";
    std::getline(std::cin, word2);

    if(areAnagrams(word1, word2) == 1) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}