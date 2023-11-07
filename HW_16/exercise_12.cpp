#include <iostream>
#include <algorithm>
#include <vector>

inline bool evenNum(const int &num) { return num % 2 == 0;}

void printVector(const std::vector<int> &vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::stable_partition(numbers.begin(), numbers.end(), evenNum);

    printVector(numbers);
    
    return 0;
}