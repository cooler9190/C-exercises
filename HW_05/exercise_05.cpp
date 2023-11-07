#include <iostream>
#include <string>
#include <vector>


void printRecurringElements(std::vector<std::string> v) {
    for(int i = 0; i < v.size(); ++i) {
        for(int j = i + 1; j < v.size(); ++j) {
            if(v[i] == v[j]) {
                std::cout << v[i] << " ";
                break;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> vec = {};
    std::string word = "";

    std::cout << "Please fill the vector with words: ";
    while(!std::cin.eof()) {
        std::cin >> word;
        vec.push_back(word);
    }

    printRecurringElements(vec);

    return 0;
}