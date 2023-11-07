#include <iostream>
#include <string>
#include <vector>


void mostCommonWord(std::vector<std::string> v) {
    std::string commonWord = "";
    int maxCount = 0;
    for(int i = 0; i < v.size(); ++i) {
        int wordCount = 0;
        for(int j = i + 1; j < v.size(); ++j) {
            if(v[i] == v[j]) {
                ++wordCount;
            }
        }

        if(maxCount < wordCount) {
            maxCount = wordCount;
            commonWord = v[i];
        }

        // if(comm)
        // if(maxCount = wordCount) {
        //     std::cout << v[i] << " ";
    }

       std::cout << commonWord << std::endl;
}
    

int main() {
    std::vector<std::string> vec = {};
    std::string word = "";

    std::cout << "Please fill the vector with words: ";
    while(!std::cin.eof()) {
        std::cin >> word;
        vec.push_back(word);
    }

    mostCommonWord(vec);

    return 0;
}