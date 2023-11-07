#include <iostream>
#include <cmath>

int binToDec(int n) {
    int decimal = 0, exponent = 0;
    
    while(n != 0) {
        int digit = n % 10;
        decimal += digit * pow(2, exponent);
        n /= 10;
        exponent++;
    }

    return decimal;
}

int main() {
    int a = 1010, b = 110101, c = 100001;

    std::cout << binToDec(a) << std::endl;
    std::cout << binToDec(b) << std::endl;
    std::cout << binToDec(c) << std::endl;

    return 0;
}