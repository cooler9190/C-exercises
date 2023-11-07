#include <iostream>

using uI = unsigned int;

uI nextInt(uI a) {
    uI oneCount = 0, nextNum = a + 1, nextCount = 0;

    while(a > 0) {
        oneCount += a & 1;
        a >>= 1;
    }

    while(true) {
        uI b = nextNum;
        while(b > 0) {
            nextCount += b & 1;
            b >>= 1;
        }
        if(oneCount != nextCount) {
            nextCount = 0;
            ++nextNum;
        } else {
            return nextNum;
            break;
        }
        
    }
}

int main() {    
    uI x = 0;

    std::cout << "Please enter a positive integer: ";
    std::cin >> x;

    std::cout << "The next integer with same number of ones is: " << nextInt(x) << std::endl;

    return 0;
}