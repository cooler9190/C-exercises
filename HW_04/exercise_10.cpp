#include <iostream>

int pow(int a, int exponent) {
    int b = 1;

    while(exponent != 0) {
        b *= a;
        exponent--;
    }

    return b;
}

int main() {
    int a = 0, exponent = 0;
    
    std::cout << "Please enter the value of a: ";
    std::cin >> a;


    std::cout << "Now enter the value of the exponent: ";
    std::cin >> exponent;

    std::cout << a << " raised to the power of " << exponent << " is: " << pow(a, exponent) << std::endl;

    return 0;
}