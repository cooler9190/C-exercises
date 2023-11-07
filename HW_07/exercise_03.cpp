#include <iostream>
#include <vector>

using si = signed int;

std::vector<si> hasSubVectorWithVal(const std::vector<si> &v, si n) {
    si sum = 0;
    std::vector<si> subVec = {};
    for(size_t i = 0; i < v.size(); ++i) {
        subVec.push_back(v[i]);
        sum = v[i];
        if(sum == n) {
            return subVec;
        }
        for(size_t j = i + 1; j < v.size(); ++j) {
            subVec.push_back(v[j]);
            sum += v[j];
            if(sum == n) {
                return subVec;
            }

            if(sum > n) {
                subVec.clear();
                break;
            }
        }
    }

    return subVec;
}

int main() {
    si n = 0, x = 0;
    std::vector<int> vec = {1, 3, 4, 2, 4, 2, 1};
    std::vector<int> subVector = {};

    std::cout << "Please enter the sum you wish to search for: ";
    std::cin >> x;

    subVector = hasSubVectorWithVal(vec, x);

    for(size_t i = 0; i < subVector.size(); ++i) {
        std::cout << subVector[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}