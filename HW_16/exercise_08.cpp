#include <iostream>
#include <vector>
#include <algorithm>

void sortInput(std::vector<int> &vec, const int &val) {
    auto iter = std::lower_bound(vec.begin(), vec.end(), val);

    vec.emplace(iter, val);
}

void fillVector(std::vector<int> &vec) {
    int num = 0;
    while(true) {
        std::cin >> num;

        if(!std::cin.fail()) {
            sortInput(vec, num);
        } else {
            break;
        }
    }
}

void printVector(const std::vector<int> &vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers;
    int val = 0;

    std::cout << "Enter a number: ";
    std::cin >> val;


    std::cout << "Now enter a set of number: ";

    fillVector(numbers);

    printVector(numbers);

    if(std::binary_search(numbers.begin(), numbers.end(), val) == 1) {
        std::cout << val << " is in the set" << std::endl;
    } else {
        std::cout << val << " is not found int the set" << std::endl;
    }
    
    return 0;
}