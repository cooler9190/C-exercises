#include <iostream>
#include <vector>

using si = signed int;

std::vector<si> hasSortedSubVector(const std::vector<si> &v) {
    std::vector<si> longestSortedSubVec = {};
    std::vector<si> currentSortedSubVec = {};
    for(size_t i = 0; i < v.size(); ++i) {
        if(v[i] <= v[i + 1]) {
            currentSortedSubVec.push_back(v[i]);
        } else {
            currentSortedSubVec.push_back(v[i]);

            if(longestSortedSubVec.size() < currentSortedSubVec.size()) {
                longestSortedSubVec = currentSortedSubVec;
            }

            currentSortedSubVec.clear();
        }

        if(longestSortedSubVec.size() < currentSortedSubVec.size()) {
                longestSortedSubVec = currentSortedSubVec;
        }
    }

    return longestSortedSubVec;
}

int main() {
    si n = 0, x = 0;
    std::vector<int> vec = {1, 3, 2, 2, 4, 5, 3};
    std::vector<int> subVector = {};

    subVector = hasSortedSubVector(vec);

    for(size_t i = 0; i < subVector.size(); ++i) {
        std::cout << subVector[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}