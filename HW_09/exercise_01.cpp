#include <iostream>

bool isArrSorted(const int (&arr)[10]) {
    for(size_t i = 0; i < 10; ++i) {
        for(size_t j = i + 1; j < 10; ++j) {
            if(arr[i] > arr[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int array1[10] = {56, 67, 80, 81, 81, 82, 90, 99, 101, 101};
    
    int array2[10] = {56, 67, 80, 81, 81, 82, 90, 99, 101, 78};

    if(isArrSorted(array1) == 1) {
        std::cout << "Array1 is sorted!" << std::endl;
    } else {
        std::cout << "Array1 is not sorted!" << std::endl;
    }

    if(isArrSorted(array2) == 1) {
        std::cout << "Array2 is sorted!" << std::endl;
    } else {
        std::cout << "Array2 is not sorted!" << std::endl;
    }

    return 0;
}