#include <iostream>
#define SWAP(x, y) int tmp; tmp = x; x = y; y = tmp;

int main() {
    int a = 10, b = 2000;

    SWAP(a, b);

    std::cout << a << " " << b << std::endl;

    return 0;
}