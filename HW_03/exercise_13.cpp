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

int octToDec(std::string n) {
    int decimal = 0, exponent = 0, length = n.size();
    
    for(int i = length - 1; i >= 0; i--) {
        if(n[i] >= '0' && n[i] <= '7') {
            decimal += int((n[i]) - 48) * pow(8, exponent); 
        } else {
            continue;
        }
        exponent++;
    }

    return decimal;
}

int main() {
    std::string s = "";
    unsigned int number = 0;
    std::cout << "Please enter a number in binary, octal, decimal or hexadecimal format: ";
    std::cin >> s;

    if(s[1] == 'b') {
        number = binToDec(s);
        std::cout << "Number " << s << " is in binary, which in decimal is: " << number << std::endl;
        return 0;

    } else if(s[1] == 'x') {
        number = hexToDec(s);
        std::cout << "Number " << s << " is in hexadecimal, which in decimal is: " << number << std::endl;
        return 0;

    } else if(s[0] == '0') {
        number = octToDec(s);
        std::cout << "Number " << s << " is in octal, which in decimal is: " << number << std::endl;
    } else {
        std::cout << "Number " << s << " is in decimal" << std::endl;
    }
    


    return 0;
}