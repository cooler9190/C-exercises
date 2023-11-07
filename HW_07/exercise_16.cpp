#include <iostream>
#include <string>
#include <stdexcept>

struct Exception {
   std::string message = "Cannot devide by 0!";
};


void division(const int &a, const int &b) {

    if(b == 0) {
        throw Exception();
    } else if((a < 0 && b >= 0) || (a >= 0 && b < 0)) {
        throw std::invalid_argument("Arguments have different signs!");
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
    } catch (std::invalid_argument const &invArg) {
        std::cout << "The arguments are invalid!" << std::endl;
        std::cout << invArg.what() << std::endl;
    }

    return 0;
}