#include <iostream>

using uI = unsigned int;

uI totalOnes(uI a) {
    uI totalCount = 0;

    while(a != 0) {
        int i = a;
        while(i > 0) {
            totalCount += i & 1;
            i >>= 1;
        }
        --a;
    }

    return totalCount;
}

int main() {    
    uI x = 0;

    std::cout << "Please enter a positive integer: ";
    std::cin >> x;

    std::cout << "The total count of ones from 1 to " << x << " is: " << totalOnes(x) << std::endl;

    return 0;
}