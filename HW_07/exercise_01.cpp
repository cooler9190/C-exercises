#include <iostream>

void printLuckyNumber(const int& n) {
    int luckyNumber = 7;
    for(int i = 0; i < n; ++i) {
        std::cout << luckyNumber << " ";
        luckyNumber += 9;
    }
}

int main() {
    int n = 0;

    std::cout << "Please enter the amount lucky numbers to be generated: ";
    std::cin >> n;

    printLuckyNumber(n);

    return 0;
}