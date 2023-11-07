#include <iostream>
#include <string>
#include <cmath>

int binToDec(std::string n) {
    int decimal = 0, exponent = 0, length = n.size();
    
    for(int i = length - 1; i >= 0; i--) {
        if(n[i] == '0') {
            decimal += int((n[i]) - 48) * pow(2, exponent); 
        } else if(n[i] == '1'){
            decimal += int((n[i]) - 48) * pow(2, exponent);
        } else {
            continue;
        }
        exponent++;
    }

    return decimal;
}

int main() {
    std::string binNumber = "";

    std::cout << "Please enter a binary number(only 0 and 1): ";
    std::cin >> binNumber;
    
    std::cout << binToDec(binNumber) << std::endl;

    return 0;
}