#include <iostream>
#include <vector>

void fillVectors(std::vector<int> v1, std::vector<int> &v2, std::vector<int> &v3) {
    for(int i = 0; i < v1.size(); i++) {
        if(v1[i] % 2 == 0) {
            v2.push_back(v1[i]);
        } else {
            v3.push_back(v1[i]);
        }
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evenNumbers = {};
    std::vector<int> oddNumbers = {};

    fillVectors(numbers, evenNumbers, oddNumbers);

    for(int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;

    for(int i = 0; i < evenNumbers.size(); i++) {
        std::cout << evenNumbers[i] << " ";
    }

    std::cout << std::endl;

    for(int i = 0; i < oddNumbers.size(); i++) {
        std::cout << oddNumbers[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}