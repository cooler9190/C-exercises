#include <iostream>

template <typename T, typename U>
void swap(T& a, U& b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int num1 = 10, num2 = 20;
    double doubleNum = 15.5;
    char letter1 = 'A', letter2 = 'B';

    swap(num1, num2);

    std::cout << num1 << " " << num2 << std::endl;

    swap(num1, doubleNum); 

    std::cout << num1 << " " << doubleNum << std::endl;

    swap(letter1, letter2);

    std::cout << letter1 << " " << letter2 << std::endl;

    //swap<char>(letter1, num2);

    //std::cout << letter1 << " " << num2 << std::endl;

    return 0;
}