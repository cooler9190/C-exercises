#include <iostream>

void swap(int a, int b) {
    int c = 0;
    c = a;
    a = b;
    b = c;

    std::cout << a << " " << b << std::endl;
}

int main() {
    int a = 10, b = 20;

    swap(a, b);

    return 0;
}