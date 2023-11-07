#include <iostream>

using uI = unsigned int;

uI hammingDistance(uI a, uI b) {
    uI distance = a ^ b;
    uI difCount = 0;

    while(distance > 0) {
        difCount += distance & 1;
        distance >>= 1;
    }

    return difCount;
}

int main() {    
    uI x = 0, y = 0;

    std::cout << "Please enter two positive integers: ";
    std::cin >> x >> y;

    std::cout << "The distance between " << x << " and " << y << " is " << hammingDistance(x, y) << std::endl;

    return 0;
}