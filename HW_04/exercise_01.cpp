#include <iostream>

int a = 5;

void print() {
    int a = 10;

    std::cout << a << " " << ::a << std::endl;
}

int main() {

    print();

    return 0;
}