#include <iostream>

using ullI = unsigned long long int;

constexpr ullI factorial(int &n) {
    if(n < 0) {
        std::cout << "Factorial of a negative number does not exist!" << std::endl;
        return 1;
    }
    ullI x = 1;
    for(int i = 1; i <= n; i++) {
        x *= i;
    }

    return x;
}

int main() {
    int n = 0;

    std::cout << "Please enter an integer value: ";
    std::cin >> n;

    std::cout << "Factoriel of " << n << " is: " << factorial(n) << std::endl;

    return 0;
}