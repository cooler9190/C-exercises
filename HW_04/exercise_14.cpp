#include <iostream>

float clamp(float value, float minValue, float maxValue) {
    if(value >= minValue && value <= maxValue) {
        return value;
    } else if (value > maxValue){
        return maxValue;
    } else {
        return minValue;
    }
}

int main() {
    float x = 0, y = 0, z = 0;

    std::cout <<" Please enter a floating point number and two numbers to represent the range: ";
    std::cin >> x >> y >> z;

    std::cout << clamp(x, y, z) << std::endl;

    return 0;
}