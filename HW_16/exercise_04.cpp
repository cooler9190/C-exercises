#include <iostream>
#include <vector>
#include <algorithm>

inline int square(int &n) { return (n *= n); }

void print(const std::vector<int> &vec) {
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {2, 14, 6, 85, 39, 19};

    std::vector<int> numbersSquared = numbers;
    
    std::transform(numbersSquared.begin(), numbersSquared.end(), numbersSquared.begin(), square);

    print(numbers);

    print(numbersSquared);

    return 0;
}