#include <iostream>
#include <string>
#include <vector>

// try with (unordered) map!!!!

using string = std::string;
using vectorString = std::vector<string>;

int countWords(vectorString &vec, const int &index) {
    int count = 1;

    for(size_t j = 0; j < vec.size(); ++j) {
        if(vec[j].back() == ',') {
            vec[j].pop_back();
        }

        if(vec[index] == vec[j] && index != j) {
            ++count;
        }
    }

    return count;
}

void printWord(vectorString &vec) {
    vectorString usedWords = {"0"};

    for(size_t i = 0; i < vec.size(); ++i) {
        bool flag = false;
        for(size_t j = 0; j < usedWords.size(); ++j) {
            if(vec[i] == usedWords[j]) {
                flag = true;
                break;
            }
        }

        if(flag == true) {
            continue;
        }
        std::cout << vec[i] << ": " << countWords(vec, i) << std::endl; 
        usedWords.push_back(vec[i]);
    }
}


int main() {
    string word = "";
    vectorString vector = {};

    while (!std::cin.eof()) {
        std::cin >> word;
        vector.push_back(word);
    }

    printWord(vector);

    return 0;
}