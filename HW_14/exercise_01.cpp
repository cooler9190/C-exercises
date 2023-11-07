#include <iostream>
#include <deque>

void printDeque(const std::deque<int> &d) {
    for(auto iter = d.begin(); iter != d.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::deque<int> d1 = {1, 3, 5, 7, 9};
    std::deque<int> d2 = {2, 4, 6, 8};

    printDeque(d1);
    printDeque(d2);

    std::swap(d1, d2);

    printDeque(d1);
    printDeque(d2);

    return 0;
}