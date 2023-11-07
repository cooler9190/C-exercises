#include <iostream>

float fmin(float a, float b) {
    if(a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    float a = 25.7, b = 25.74;

    std::cout << fmin(a, b) << " is the smaller number" << std::endl;

    return 0;
}