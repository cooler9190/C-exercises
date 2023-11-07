#include <iostream>

using ullI = unsigned long long int;

constexpr ullI fibSequence(const int &n) {
    int x = 0, y = 1, z = 0;
    for(ullI i = 1; i < n; i++) {
        z = x + y;
        x = y;
        y = z;
    }

    return z;
}

int main() {
    int n = 0;

    std::cout << "Please enter the number of the n-th Fibonacci number: ";
    std::cin >> n;

    std::cout << "The n-th Fibonacci number is: " << fibSequence(n) << std::endl;


    return 0;
}