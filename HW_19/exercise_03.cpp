#include <iostream>
#include <algorithm>

void relocateArr(int* &arr, int* &copy, const int &size) {
    std::copy(arr, arr + size, copy);

    for(size_t i = size; i < size * 2; ++i) {
        copy[i] = copy[i - 1] + 1;
    }
}

int main() {
    int number = 0, amount = 0, i = 0;

    std::cout << "Enter the amount of positive numbers you wish to enter: ";
    std::cin >> amount;

    int* arr = new int[amount];

    int* copyArr = new int[amount * 2];

    std::cout << "Now enter the numbers: ";

    while(std::cin >> number) {
        arr[i] = number;
        ++i;
    }

    relocateArr(arr, copyArr, amount);

    delete[] arr;
    arr = nullptr;

    for(size_t i = 0; i < amount * 2; ++i) {
        std::cout << copyArr[i] << " ";
    }

    std::cout << std::endl;

    delete[] copyArr;
    copyArr = nullptr;

    return 0;
}