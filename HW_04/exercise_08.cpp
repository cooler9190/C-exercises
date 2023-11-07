#include <iostream>

int floor(double a) {
    int result = a - 1;

    return result;
}

int main() {
    double a = -6.98;

    std::cout << "The closest integer to " << a << " is: " << floor(a) << std::endl;

    return 0;
}