#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> setVector(int &num) {
    std::vector<int> vec;
    while(num > 0) {
        int digit = num  % 10;
        num /= 10;
        vec.emplace_back(digit);
    }

    std::sort(vec.begin(), vec.end());

    return vec;
}

int dichoSearch(std::vector<int> &vec, const int &val) {
    int low = 0, high = vec.size() - 1;
    while(high - low > 1) {
        int mid = (high + low) / 2;

        if(vec[mid] < val) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    if(vec[low] == val) {
        return low;
    } else if(vec[high] == val){
        return high;
    } else {
        return -1;
    }
}

int main() {
    int number = 0, value = 0;

    std::cout << "Please enter a positive integer: ";
    std::cin >> number;

    std::cout << "Please enter the number you wish to search for: ";
    std::cin >> value;

    std::vector<int> numInVec = setVector(number);

    int index = dichoSearch(numInVec, value);    

    if(index != -1) {
        std::cout << value << " is present at index " << index << std::endl;
    } else {
        std::cout << value << " is not present in the container" << std::endl;
    }

    return 0;
}