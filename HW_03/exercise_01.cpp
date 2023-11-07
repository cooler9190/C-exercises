#include <iostream>
#include <vector>
#include <algorithm>

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
    int a = 23, b = 64, c = 1337; 

    decToBin(a);
    std::cout << std::endl;
    decToBin(b);
    std::cout << std::endl;
    decToBin(c);
    std::cout << std::endl;

    return 0;
}