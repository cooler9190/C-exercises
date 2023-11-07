#include <iostream>

int ciel(double a) {
    int result = a + 1;

    return result;
}

int main() {
    double a = 6.38;

    std::cout << "The closest integer to " << a << " is: " << ciel(a) << std::endl;

    return 0;
}