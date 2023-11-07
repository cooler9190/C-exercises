#include <iostream>

bool isPrime(int a) {

    if(a == 0 || a == 1) {
        return false;
    } else {
        for(int i = 2; i <= a / 2; i++) {
            if(a % i == 0) {
                return false;
                break;
            }
        }
    }

    return true;
}

int main () {
    int a = 0;

    std::cout << "Please enter a positive integer: ";
    std::cin >> a;

    if(isPrime(a)) {
        std::cout << a << " is a prime number" << std::endl;
    } else {
        std::cout << a << " is not a prime number" << std::endl;
    }

    return 0;
}