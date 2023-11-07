#include <iostream>
#include <string>
#include <vector>

using string = std::string;
using vectorString = std::vector<string>;

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

void printWord(vectorString &vec) {
    vectorString usedWords = {"0"};

    for(size_t i = 0; i < vec.size(); ++i) {
        bool flag = false;
        for(size_t x = 0; x < usedWords.size(); ++x) {
            if(usedWords[x] == vec[i]) {
                flag = true;
                break;
            }
        }

        if(flag == true) {
            continue;
        }

        std::cout << vec[i] << " ";
        usedWords.push_back(vec[i]);

        for(size_t j = i + 1; j < vec.size(); ++j) {
            if(areAnagrams(vec[i], vec[j])) {
                std::cout << vec[j] << " ";
                usedWords.push_back(vec[j]);
            }
        }
        std::cout << std::endl;
    }
}


int main() {
    string word = "";
    vectorString vector = {};

    while (!std::cin.eof()) {
        std::cin >> word;
        vector.push_back(word);
    }

    std::cout << std::endl;
    printWord(vector);

    return 0;
}