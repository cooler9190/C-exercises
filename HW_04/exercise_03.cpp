#include <iostream>
#include <cmath>

bool isEqual(float a, float b) {
    //very small number
    float epsilon = 1e-9;

    if(std::abs(a - b) < epsilon) {
        return true;
    } else {
        return false;
    }
}

int main() {
    float a = 0.00000435, b = 0.00000436;

    if(isEqual(a, b)) {
        std::cout << a << " and " << b << " are equal" << std::endl;
    } else {
        std::cout << a << " and " << b << " are not equal" << std::endl;
    }

    return 0;
}