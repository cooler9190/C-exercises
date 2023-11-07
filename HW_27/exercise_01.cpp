#include <iostream>
#include <vector>
#include <string>

template <typename T>
void maxElement(const std::vector<T> &vec) {
    T max = vec[0];
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        if(max < *iter) {
            max = *iter;
        }
    }

    std::cout << "The largest element is: " << max << std::endl;
}

int main() {
    std::vector<double> vec1 = {12, 12.4, 18, -3, -2,1, 60};
    maxElement(vec1);

    std::vector<char> vec2 = {'A', 'G', 'a', 'g'};
    maxElement(vec2);

    std::vector<std::string> vec3 = {"Hello, CodeAcademy", "Hello, CodeAcademy!"};
    maxElement(vec3);

    return 0;
}