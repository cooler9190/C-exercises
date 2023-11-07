#include <iostream>

using uI = unsigned int;

uI numberOfZeros(uI num) {
    uI count = 0;
    while(num > 0) {
        if((num & 1) == 0) {
            ++count;
        } else {
            break;
        }
        num >>= 1;
    }

    return count;
}

int main() {    
    uI number = 0;

    std::cout << "Please enter a positive integer value: ";
    std::cin >> number;

    std::cout << "The number of trailing zeros in " << number << " is " << numberOfZeros(number) << std::endl;

    return 0;
}