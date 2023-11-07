#include <iostream>
#include <string>
#include <cmath>

int hexToDec(std::string n) {
    int decimal = 0, exponent = 0, length = n.size();
    
    for(int i = length - 1; i >= 0; i--) {
        if(islower(n[i])) {
            n[i] = toupper(n[i]);
        }
        if(n[i] >= '0' && n[i] <= '9') {
            decimal += int((n[i]) - 48) * pow(16, exponent); 
        } else if(n[i] >= 'A' && n[i] <= 'F'){
            decimal += int((n[i]) - 55) * pow(16, exponent);
        } else {
            continue;
        }
        exponent++;
    }

    return decimal;
}

int main() {
    std::string hexNumber = "";

    std::cout << "Please enter a hexadecimal number(only numbers from 0 to 9 and letters from A to F): ";
    std::cin >> hexNumber;
    
    std::cout << hexToDec(hexNumber) << std::endl;

    return 0;
}