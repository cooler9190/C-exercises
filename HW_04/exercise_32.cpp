#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

std::string decToBin(int a) {
    std::string binNumber = ""; 

    while(a != 0) {
        int digit = a % 2;
        binNumber.push_back(48 + digit);
        a /= 2;
    }

    std::reverse(binNumber.begin(), binNumber.end());

    return binNumber;
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

std::string decToOctal(int a) {
    std::string octalNumber = ""; 

    while(a != 0) {
        int digit = a % 8;
        octalNumber.push_back(48 + digit);
        a /= 8;
    }

    std::reverse(octalNumber.begin(), octalNumber.end());

    return octalNumber;
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

bool isEven(int a) {
    if(a % 2 == 0) {
        return true;
    } else {
        return false;
    }

}

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

int numberOfDigits(int a) {
    int numCount = 0;
    while(a != 0) {
        a /= 10;
        numCount++;
    }

    return numCount;
}

int sumOfDigits(int a) {
    int sum = 0, digit = 0;
    while(a != 0) {
        digit = a % 10;
        a /= 10;
        sum += digit;
    }

    return sum;
}

int reverseNumber(int a) {
    int reverse = 0, digit = 0;
    while(a != 0) {
        digit = a % 10;
        reverse = reverse * 10 + digit;
        a /= 10;
    }

    return reverse;
}

bool isPalindrome(int a, int rev) {
    if(a == rev) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::string n = "", bin = "", oct = "", hex = "";
    int x = 0, rev = 0;

    std::cout << "Please enter a number in binary, octal, decimal or hexadecimal format: ";
    std::cin >> n;

    if(n[1] == 'b') {
        bin = n;
        x = binToDec(n);
        oct = decToOctal(x);
        hex = decToHex(x);
    } else if(n[1] == 'x') {
        hex = n;
        x = hexToDec(n);
        bin = decToBin(x);
        oct = decToOctal(x);
    } else if(n[0] == '0') {
        oct = n;
        x = octToDec(n);
        bin = decToBin(x);
        hex = decToHex(x);
    } else {
        x = std::stoi(n);
        bin = decToBin(x);
        oct = decToOctal(x);
        hex = decToHex(x);
    }

    std::cout << "The number " << n << " in decimal format is: " << x << std::endl;
    std::cout << "The number " << n << " in binary format is: " << bin << std::endl;
    std::cout << "The number " << n << " in octal format is: " << oct << std::endl;
    std::cout << "The number " << n << " in hexadecimal format is: " << hex << std::endl;

    if(isEven(x) == true) {
        std::cout << x << " is an even number." << std::endl;
    } else {
        std::cout << x << " is an odd number." << std::endl;
    }

    std::cout << "The number of digits in decimal format is: " << numberOfDigits(x) << std::endl;

    std::cout << "The sum of the digits in decimal format is: " << sumOfDigits(x) << std::endl;

    rev = reverseNumber(x);
    std::cout << "The number in reverse look like this: " << rev << std::endl;

    if(isPalindrome(x, rev)) {
        std::cout << x << " is a palindrome." << std::endl;
    } else {
        std::cout << x << " is not a palindrome." << std::endl;
    }

    return 0;
}