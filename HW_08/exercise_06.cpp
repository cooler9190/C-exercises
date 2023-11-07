#include <iostream>
#include <array>

int findUniqueNum(const std::array<int, 10> &arr) {
    int uniqueNum = 0;
    for(size_t i = 0; i < arr.size(); i++) {
        for(size_t j = 0; j < arr.size(); j++) {
            if(arr[i] == arr[j] && i != j) {
                uniqueNum = 0;
                break;
            } else {
                 uniqueNum = arr[i];
            }
        }

        if(uniqueNum != 0) {
            break;
        }
    }

    if(uniqueNum == 0) {
        return 0;
    } else {
        return uniqueNum;
    }
}

int main()
{
    srand(time(0));
    std::array<int, 10> array{78, 37, 33, 89, 78, 40, 60, 37, 33, 49};

    std::cout << findUniqueNum(array) << std::endl;

    return 0;
}