#include <iostream>

using uI = unsigned int;

void isNumberOfOnesEven(uI num) {
    uI count = 0;
    while(num > 0) {
        if(num & 1 == 1) {
            ++count;
        }

        num >>= 1;
    }

    if(count % 2 == 0) {
        std::cout << "The number of 1-s are even" << std::endl;
    } else {
        std::cout << "The number of 1-s are odd" << std::endl;
    }

}

int main() {    
    uI number = 0;

    std::cout << "Please enter a positive integer value: ";
    std::cin >> number;

    isNumberOfOnesEven(number);

    return 0;
}