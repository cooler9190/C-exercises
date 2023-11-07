#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

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
    std::string a = "0XFF", b = "0xfefe", c = "1A";

    std::cout << hexToDec(a) << std::endl;
    std::cout << hexToDec(b) << std::endl;
    std::cout << hexToDec(c) << std::endl;

    return 0;
}