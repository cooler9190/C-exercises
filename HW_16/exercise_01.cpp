#include <iostream>
#include <vector>
#include <algorithm>

void fillVector(std::vector<int> &vec) {
    int num = 0;
    while(!std::cin.fail()) {
        std::cin >> num;
        vec.emplace_back(num);
    }
}

void nullValues(std::vector<int> &vec) {
    for(size_t i = 0; i <= vec.size() - 1; ++i) {
        int n = 1;
        bool flag = false;
        for(size_t j = i + 1; j < vec.size(); ++j) {
            if(vec[i] == vec[j]) {
                flag = true;
                ++n;
            } else {
                break;
            }
        }
        if(flag == true) {
            std::fill_n(vec.begin() + i, n, 0);
        }
    }
}

void printVector(const std::vector<int> &vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers;

    fillVector(numbers);

    nullValues(numbers);

    printVector(numbers);
    
    return 0;
}