#include <iostream>
#include <string>
#include <algorithm>

std::string decToHex(int a) {
    std::string hexNumber = ""; 

    while(a != 0) {
        int digit = a % 16;
        if(digit < 10) {
            hexNumber.push_back(48 + digit);
        } else {
            hexNumber.push_back(55 + digit);
        }
        a /= 16;
    }

    std::reverse(hexNumber.begin(), hexNumber.end());

    return hexNumber;
}

int main() {
    int a = 12, b = 256, c = 51966;
    
    std::cout << decToHex(a) << std::endl;
    std::cout << decToHex(b) << std::endl;
    std::cout << decToHex(c) << std::endl;

    return 0;
}