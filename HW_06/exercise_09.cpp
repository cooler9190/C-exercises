#include <iostream>

using uI = unsigned int;

uI numberOfOnes(uI num) {
    uI count = 0;
    while(num > 0) {
        if(num & 1 == 1) {
            ++count;
        }

        num >>= 1;
    }

    return count;
}

int main() {    
    uI number = 0;

    std::cout << "Please enter a positive integer value: ";
    std::cin >> number;

    std::cout << "The number of 1-s in " << number << " are " << numberOfOnes(number) << std::endl;
    return 0;
}