#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    vec.reserve(10);

    for(int i = 0; i < 10; ++i) {
        vec.emplace_back(i);
        std::cout << "Vector size: " << vec.size() << " Vector capacity: " << vec.capacity() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}