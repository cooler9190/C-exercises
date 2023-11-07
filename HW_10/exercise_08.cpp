#include <iostream>
#include <initializer_list>

using ptrCondition = bool (*)(int);

int findFirstNum(std::initializer_list<int> l, ptrCondition condition) {
    for(const int &value : l) {
        if(condition(value) == 1) {
            return value;
        }
    }

    return 0;
}

inline bool firstNegative(const int num) { return num < 0; }

inline bool firstEven(const int num) { return (num % 2) == 0; }



int main() {
    std::initializer_list<int> list = {1, 2, 3, 4, 5, -5, 6};

    int first_negative = findFirstNum(list, firstNegative);
    int first_even = findFirstNum(list, firstEven);

    if(first_negative == 0) {
        std::cout << "There asre no negative numbers in the list." << std::endl;
    } else {
        std::cout << "The first negative number is: " << first_negative << std::endl;
    }

    if(first_even == 0) {
        std::cout << "There asre no even numbers in the list." << std::endl;
    } else {
        std::cout << "The first even number is: " << first_even << std::endl;
    }

    return 0;
}