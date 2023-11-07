#include <iostream> 
#include <string>
#include <cmath>

int numberToDec(int n, int base) {
    int decimal = 0, exponent = 0;
    
    while(n != 0) {
        int digit = n % 10;
        decimal += digit * pow(base, exponent);
        n /= 10;
        exponent++;
    }

    return decimal;
}

int hexToDec(std::string hexNumber) {
    int length = hexNumber.size(), decimal = 0, exponent = 0;

    for(int i = length - 1; i >= 0; i--) {
        if(islower(hexNumber[i])) {
            hexNumber[i] = toupper(hexNumber[i]);
        }
        if(hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += int((hexNumber[i]) - 48) * pow(16, exponent); 
        } else if(hexNumber[i] >= 'A' && hexNumber[i] <= 'F'){
            decimal += int((hexNumber[i]) - 55) * pow(16, exponent);
        }
        exponent++;
    }

    return decimal;
}

int main() {
    int a = 1100, b = 016;
    std::string c = "0xAB";

    std::cout << numberToDec(a, 2) << std::endl;
    std::cout << numberToDec(b, 8) << std::endl;
    std::cout << hexToDec(c) << std::endl;


    return 0;
}