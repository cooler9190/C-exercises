#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std::placeholders;

void fillVector(std::vector<std::string> &vec) {
    std::string line = "";
    while(true) {
        std::getline(std::cin, line);

        if(!std::cin.fail()) {
            vec.emplace_back(line);
        } else {
            break;
        }
    }
}

void printVector(const std::vector<std::string> &vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
}

void stringRev(std::string &s) {
    std::reverse(s.begin(), s.end());
}

int main() {
    std::vector<std::string> strings;
    
    fillVector(strings);

    printVector(strings);

    std::for_each(strings.begin(), strings.end(), stringRev);

    printVector(strings);
    
    return 0;
}