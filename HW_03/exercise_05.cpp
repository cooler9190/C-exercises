#include <iostream>
#include <string>
#include <vector>
#include <cmath>

void decToBin(int n) {
    std::vector <int> numberInBinary;
    int binDigit = 0;

    while(n != 0) {
        binDigit = n % 2;
        numberInBinary.push_back(binDigit);
        n /= 2;
    }

    for(int i = numberInBinary.size() - 1; i >= 0; i--) {
        std::cout << numberInBinary[i];
    }
}

int main() {
    int a = 128, b = 02, decimal = 0, exponent = 0;
    std::string c = "0x001f"; 

    decToBin(a);
    std::cout << std::endl;

   while(b != 0) {
        int digit = b % 10;
        if(digit > 0) {
            decimal += pow(8, exponent);
        }
        b /= 10;
        exponent++;
    }

    decToBin(decimal);
    std::cout << std::endl;

    decimal = 0, exponent = 0;
    for(int i = c.size() - 1; i >= 0; i--) {
        if(islower(c[i])) {
            c[i] = toupper(c[i]);
        }
        toupper(c[i]);
        if(c[i] >= '0' && c[i] <= '9') {
            decimal += int((c[i]) - 48) * pow(16, exponent); 
        } else if(c[i] >= 'A' && c[i] <= 'F'){
            decimal += int((c[i]) - 55) * pow(16, exponent);
        }
        exponent++;
    }

    decToBin(decimal);
    std::cout << std::endl;    

    return 0;
}