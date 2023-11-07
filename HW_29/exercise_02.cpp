#include <iostream>
#define IS_EVEN(x) (x % 2 == 0 ? "even" : "odd")
#define IS_ODD(x) (x % 2 == 1 ? "odd" : "even")


int main() {
    int a = 15, b = 2354;

    std::cout << IS_EVEN(a) << std::endl;

    std::cout << IS_ODD(b) << std::endl;

    return 0;
}