#include <iostream>

using uI = unsigned int;

uI nextInt(uI a) {
    uI rigthmost = 0, position = 0;

    while((a & position) == 0) {
        a >>= 1;
        ++rigthmost;
    }

    
}

int main() {    
    uI x = 0;

    std::cout << "Please enter a positive integer: ";
    std::cin >> x;

    std::cout << "The next integer with same number of ones is: " << nextInt(x) << std::endl;

    return 0;
}

