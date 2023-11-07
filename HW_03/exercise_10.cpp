#include <iostream>
#include <cmath>
#include <string>

void biggestNumber(int base, int intCount) {
    int biggestNumber = 0;
    if(base == 2) {
        int number = 1, digit = 10, exponent = 0;
        for(int i = 1; i < intCount; i++) {
            number += digit;
            digit *= 10;
        }

        int biggestBinary = number;

        while(number != 0) {
            int digit = number % 10;
            biggestNumber += digit * pow(2, exponent);
            number /= 10;
            exponent++;
        }

        std::cout << "The biggest binary number is " << biggestBinary << " which in decimal is: " << biggestNumber << std::endl;

    } else if(base == 8) {
        int number = 7, digit = 10, exponent = 0;
        for(int i = 1; i < intCount; i++) {
            number *= digit;
            number += 7;
        }

        int biggestOctal = number;

        while(number != 0) {
            int digit = number % 10;
            biggestNumber += digit * pow(8, exponent);
            number /= 10;
            exponent++;
        }

        std::cout << "The biggest octal number is " << biggestOctal << " which in decimal is: " << biggestNumber << std::endl;
    
    } else if(base == 10) {
        int number = 9, digit = 10, exponent = 0;
        for(int i = 1; i < intCount; i++) {
            number *= digit;
            number += 9;
        }

        biggestNumber = number;
        std::cout << "The boggest decimal number is " << biggestNumber << std::endl;

    } else if(base == 16) {
        char number = 'F';
        std::string hexNumber = "F";
        int exponent = 0;
        for(int i = 1; i < intCount; i++) {
            hexNumber += number; 
        }

        int length = hexNumber.size();

        for(int i = length - 1; i >= 0; i--) {
            if(hexNumber[i] >= '0' && hexNumber[i] <= '9') {
                biggestNumber += int((hexNumber[i]) - 48) * pow(16, exponent); 
            } else if(hexNumber[i] >= 'A' && hexNumber[i] <= 'F'){
                biggestNumber += int((hexNumber[i]) - 55) * pow(16, exponent);
            }
            exponent++;
        }

        std::cout << "The biggest hex number is " << hexNumber << " which in decimal is: " << biggestNumber << std::endl;
    } else {
        std::cout << "Unsuported base conversion." << std::endl;
    }
}

int main() {
    int base = 0, intCount = 0;

    std::cout << "Please enter a base(2, 8, 10, 16) and number of digits: ";
    std::cin >> base >> intCount;

    if(std::cin.fail()) {
        std::cout << "Wrong input!" << std::endl;
        return 0;
    }

    biggestNumber(base, intCount);

    return 0;
}