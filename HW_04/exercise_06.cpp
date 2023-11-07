#include <iostream>

double abs(double a) {
    if(a < 0) {
        a *= -1; 
    }

    return a;
}

int main() {
    float a = -25.7, b = 25.74;

    std::cout << "Absolute value is: " << abs(a) << std::endl;
    std::cout << "Absolute value is: " << abs(b) << std::endl;

    return 0;
}