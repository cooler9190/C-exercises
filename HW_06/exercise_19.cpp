#include <iostream>

using uI = unsigned int;

bool isAlternate(uI a) {

    // if(a > 1) {
    //     return ((a & (a >> 1))) == 0;
    // } else {
    //     return false;
    // }

    switch (a > 1)
    {
    case 1:
        return ((a & (a >> 1))) == 0;
        break;
    
    default:
        return false;
        break;
    }
}

int main() {    
    uI x = 0;

    std::cout << "Please enter a positive integer: ";
    std::cin >> x;

    if(isAlternate(x) == 1) {
        std::cout << "The number " << x << " is alternating " << std::endl;
    } else {
        std::cout << "The number " << x << " is not alternating " << std::endl;
    }
    

    return 0;
}