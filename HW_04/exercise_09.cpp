#include <iostream>

int round(double a) {
    int result = a + 0.5;


    return result;
}

int main() {
    double a = 6.345, b = 6.5678;

    std::cout << round(a) << " " << round(b) << std::endl;

    return 0;
}