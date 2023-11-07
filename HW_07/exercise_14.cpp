#include <iostream>
#include <stdexcept>

void division(const int &a, const int &b) {

    if(b == 0) {
        throw std::exception();
    } else {
        std::cout << a / b << std::endl;
    }
}

int main() {
    int a = 0, b = 0;

    std::cout << "Please enter the values of a and b: ";
    std::cin >> a >> b;

    try {
        division(a, b);
    } catch (const std::exception &err){
        std::cerr << "Exception caught! Cannot divide by 0!" << std::endl;
    }

    return 0;
}