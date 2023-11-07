#include <iostream>

using uI = unsigned int;

uI longestSet(uI a) {
    uI setLength = 0;

    while(a > 0) {
        a = (a &(a << 1));
        ++setLength;
    }

    return setLength;
}

int main() {    
    uI x = 0;

    std::cout << "Please enter a positive integer: ";
    std::cin >> x;

    std::cout << "The longest set is " << longestSet(x) << std::endl;

    return 0;
}