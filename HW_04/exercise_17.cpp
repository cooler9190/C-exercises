#include <iostream>

void fibSequence(int n) {
    int x = 0, y = 1, z = 0;
    for(int i = 0; i <= n; i++) {
        std::cout << x << " ";
        z = x + y;
        x = y;
        y = z;
    }
}

int main() {
    int n = 0;

    std::cout << "Please enter the number of the n-th Fibonacci number: ";
    std::cin >> n;

    std::cout << "The Fibonacci sequence is: ";
    fibSequence(n);

    std::cout << std::endl;

    return 0;
}