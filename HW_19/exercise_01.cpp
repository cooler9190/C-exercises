#include <iostream>

int sum(int* &arr, const int &size) {
    int sum = 0;
    for(size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int number = 0, amount = 0, i = 0;

    std::cout << "Enter the amount of positive numbers you wish to enter: ";
    std::cin >> amount;

    int* arr = new int[amount];

    std::cout << "Now enter the numbers: ";

    while(std::cin >> number) {
        arr[i] = number;
        ++i;
    }

    std::cout << "The sum of the input numbers is: " << sum(arr, amount) << std::endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}