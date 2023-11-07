#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void fillVec(const std::string &txt, std::vector<std::string> &vec) {
    int size = txt.size();
    std::string word = "";

    for(auto iter = txt.begin(); iter != txt.end(); ++iter) {
        if(!isspace(*iter)) {
            word += *iter;
        } else {
            vec.emplace_back(word);
            word.clear();
        }
    }

    if(!word.empty()) {
        vec.emplace_back(word);
    }
}

void copyUniqueVec(std::vector<std::string> &vec, std::vector<std::string> &copyVec) {
    std::sort(vec.begin(), vec.end());

    copyVec.resize(vec.size());

    std::unique_copy(vec.begin(), vec.end(), copyVec.begin());
}

void printVector(const std::vector<std::string> &vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::string txt = "";
    std::vector<std::string> words, wordsCopy;
    std::getline(std::cin, txt);

    fillVec(txt, words);

    copyUniqueVec(words, wordsCopy);

    printVector(words);

    printVector(wordsCopy);
}