#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

void fillArray(std::array<int, 10> &arr, const int &begin, const int &end) {
    for(size_t i = 0; i < arr.size(); ++i) {
        arr[i] = (rand() % (end - begin + 1) + begin);
    }
}

int main() {
    srand(time(0));
    std::array <int, 10> array;
    int start = 0, end = 0;
    
    std::cout << "Please enter the range of acceptable numbers: ";
    std::cin >> start >> end;

    fillArray(array, start, end);

    for(size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}