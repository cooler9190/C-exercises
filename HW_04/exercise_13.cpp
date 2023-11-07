#include <iostream>

float clampBelow(float value, float minValue) {
    if(value < minValue) {
        return value;
    } else {
        return minValue;
    }
}

int main() {
    float x = 0, y = 0;

    std::cout <<" Please enter two floating point numbers: ";
    std::cin >> x >> y;

    std::cout << clampBelow(x, y) << std::endl;

    return 0;
}