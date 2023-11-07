#include <iostream>
#include <string>

template <typename T>
T bigger(const T& a, const T& b) {
    return a > b ? a : b;
}

int main() {
    int a = -1, b = -2;
    std::cout << bigger(a, b) << std::endl;

    float aF = 1.576, bF = 1.577;
    std::cout << bigger(aF, bF) << std::endl;

    std::string aS = "Hello, World!", bS = "Hello, CodeAcademy!";
    std::cout << bigger(aS, bS) << std::endl;

    return 0;
}