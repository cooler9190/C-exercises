#include <iostream>
#include <string>

struct Exception {
   std::string message = "Cannot devide by 0!";
};

void division(const int &a, const int &b) {

    if(b == 0) {
        throw Exception();
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
    } catch (const Exception &exc){
        std::cerr << "Exception caught!" << std::endl;
        std::cout << exc.message << std::endl;
    }

    return 0;
}