#include <iostream>
#include <initializer_list>

auto checkForIntegerSequence(const std::initializer_list<double> &l) -> bool{
    for(double val : l) {
        if(val == static_cast<int>(val) && val) {
            return true;
        }
    }

    return false;
}

int main() {
    std::initializer_list<double> list = {1.8, 2.4, 3.8, 4.5, 5.9, 5.7, 6.8};

    if(checkForIntegerSequence(list) == 1) {
        std::cout << "The list includes a sequence of integers" << std::endl; 
    } else {
        std::cout << "The list does not include a sequence of integers" << std::endl;
    }



    return 0;
}