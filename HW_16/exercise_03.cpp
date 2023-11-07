#include <iostream>
#include <vector>
#include <algorithm>
using uI = unsigned int;

bool hasZero(uI num) {
    while(num > 0) {
        if((num & 1) == 0) {
            return true;
        }

        num >>= 1;
    }

    return false;
}

auto deleteNumWithZeros(std::vector<int> &vec) {

    std::vector<int>::iterator it = std::remove_if(vec.begin(), vec.end(), hasZero);

    return it;
}

int main() {
    std::vector<int> numbers = {13, 3, 7, 15, 145, 31};

    auto newEnd = deleteNumWithZeros(numbers);

    for(auto iter = numbers.begin(); iter != newEnd; ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
    
    return 0;
}