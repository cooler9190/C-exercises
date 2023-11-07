#include <iostream>

float clampAbove(float value, float maxValue) {
    if(value > maxValue) {
        return maxValue;
    } else {
        return value;
    }
}

int main() {
    float x = 0, y = 0;

    std::cout <<" Please enter two floating point numbers: ";
    std::cin >> x >> y;

    std::cout << clampAbove(x, y) << std::endl;

    return 0;
}