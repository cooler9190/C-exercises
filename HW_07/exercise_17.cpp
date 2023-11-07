#include <iostream>
#include <string>
#include <stdexcept>


void division(const int &a, const int &b) {

    if(b == 0) {
        throw std::runtime_error("Cannot divide by 0!");
    } else if((a < 0 && b >= 0) || (a >= 0 && b < 0)) {
        throw std::invalid_argument("Arguments have different signs!");
    } else {
        std::cout << a / b << std::endl;
    }
}

void loop() {
    int a = 0, b = 0;

    while(!std::cin.eof()) {
        std::cout << "Please enter the values of a and b: ";
        std::cin >> a >> b;

        try {
            division(a, b);
        } catch (const std::runtime_error &exc){
            std::cerr << "Exception caught in loop function!" << std::endl;
            throw std::runtime_error("Error! " + static_cast<std::string>(exc.what()));
        } catch (const std::invalid_argument &invArg) {
            std::cerr << "Exception caught in loop function!" << std::endl;
            throw std::invalid_argument("Error! " + static_cast<std::string>(invArg.what()));
        }


    }
}

int main() {
    try {
        loop();
    } catch (const std::runtime_error &exc){
        std::cerr << "Exception caught in main!" << std::endl;
        std::cout << exc.what() << std::endl;
    } catch (const std::invalid_argument &invArg) {
        std::cout << "Exception caught in main!" << std::endl;
        std::cout << invArg.what() << std::endl;
    }

    return 0;
}