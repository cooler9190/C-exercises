#include <iostream>
#include <vector>

using si = signed int;

bool hasSubVectorZero(const std::vector<si> &v) {
    si sum = 0;
    for(size_t i = 0; i < v.size(); ++i) {
        sum = v[i];
        if(sum == 0) {
            return true;
        }
        for(size_t j = i + 1; j < v.size(); ++j) {
            sum += v[j];
            if(sum == 0) {
                return true;
            }
            if(sum > 0) {
                break;
            }
        }
    }

    return false;
}

int main() {
    si n = 0;
    std::vector<int> vec = {};

    std::cout << "Please fill the vector with any amount of numbers: ";
    while(!std::cin.eof()) {
        std::cin >> n;
        vec.push_back(n);
    }

    if(hasSubVectorZero(vec) == 1) {
        std::cout << "The vector has a sub-vector with sum of zero." << std::endl;
    } else {
        std::cout << "The vector does not have a sub-vector with sum of zero." << std::endl;
    }

    return 0;
}