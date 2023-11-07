#include <iostream>

constexpr int pow(const int &a, int defaultExponent = 2) {
    int b = 1;

    while(defaultExponent != 0) {
        b *= a;
        --defaultExponent;
    }

    return b;
}

int main() {
    int number = 0, exponent = 0, size = 0;

    std::cout << "Please enter the value and the exponent to which you are going to raise the value: ";
    std::cin >> number >> exponent;

    if(std::cin.fail()) {
        std::cerr << "Wrong input!" << std::endl;
        std::cout << "Function will use defalt value." << std::endl;

        size = pow(number);
        int arr[size];
        
    } else {
        size = pow(number, exponent);
        int arr[size];
    }

    return 0;
}
