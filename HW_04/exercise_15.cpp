#include <iostream>

int fibSequence(int n) {
    if(n <= 1) {
        return n;
    }
    return fibSequence(n - 1) + fibSequence(n - 2);
}

int main() {
    int n = 0;

    std::cout << "Please enter the number of the n-th Fibonacci number: ";
    std::cin >> n;

    std::cout << "The n-th Fibonacci number is: " << fibSequence(n) << std::endl;

    return 0;
}