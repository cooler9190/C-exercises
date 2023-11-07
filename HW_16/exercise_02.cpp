#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

bool isDigitFound(int num, const int &val) {
    while(num > 0) {
        int digit = num  % 10;
        if(digit == val) {
            return false;
        }
        num /= 10;
    }

    return true;
}

int findNum(std::vector<int> &vec, const int &val) {

    std::vector<int>::iterator it = std::find_if(vec.begin(), vec.end(), std::bind(isDigitFound, _1, val));

    return *it;
}

int main() {
    std::vector<int> numbers = {123, 324, 5627, 89, 145};
    int value = 0;

    std::cout << "Enter a digit from 0 to 9: ";
    std::cin >> value;

    std::cout << "The first number without the value digit is: "<< findNum(numbers, value) << std::endl;
    
    return 0;
}