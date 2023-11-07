#include <iostream>

int sum(int* &arr, const int &size) {
    int sum = 0;
    for(size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum;
}

void reverseArr(int* &arr, int* &copy, const int &size) {
    for(size_t i = 0; i < size; ++i) {
        copy[i] = arr[size - 1 - i]; 
    }
}

int main() {
    int number = 0, amount = 0, i = 0;

    std::cout << "Enter the amount of positive numbers you wish to enter: ";
    std::cin >> amount;

    int* arr = new int[amount];

    int* copyArr = new int[amount];

    std::cout << "Now enter the numbers: ";

    while(std::cin >> number) {
        arr[i] = number;
        ++i;
    }

    std::cout << "The sum of the input numbers is: " << sum(arr, amount) << std::endl;

    reverseArr(arr, copyArr, amount);

    for(size_t i = 0; i < amount; ++i) {
        std::cout << copyArr[i] << " ";
    }

    std::cout << std::endl;

    delete[] arr;
    delete[] copyArr;
    arr = nullptr;
    copyArr = nullptr;

    return 0;
}