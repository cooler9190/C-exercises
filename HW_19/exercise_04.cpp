#include <iostream>
#include <algorithm>

void resizeArr(int* &arr, int &size) {
    int* copy = new int[size * 2];
    std::copy(arr, arr + size, copy);

    delete[] arr;
    arr = copy;
    size *= 2;
}

int main() {
    int number = 0, amount = 0, i = 0;

    std::cout << "Enter the amount of positive numbers you wish to enter: ";
    std::cin >> amount;

    int* arr = new int[amount];

    std::cout << "Now enter the numbers: ";

    while(std::cin >> number) {
        if(i == amount) {
            resizeArr(arr, amount);
        }
        arr[i] = number;
        ++i;
    }

    for(size_t i = 0; i < amount; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}