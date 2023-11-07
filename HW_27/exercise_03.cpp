#include <iostream>
#include <string>

template <typename T>
size_t size(T (&arr)) {
    return *(&arr + 1) - arr;
}

int main() {
    int arrInt[10] = {0};

    std::cout << size(arrInt) << std::endl;

    char arrChar[] = {"Hello, World!"};

    std::cout << size(arrChar) << std::endl;

    std::string arrStr[] = {"Hello, World!", "Hello, CodeAcademy!"};

    std::cout << size(arrStr) << std::endl;

    return 0;
}