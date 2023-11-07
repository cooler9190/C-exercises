#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>

template <typename T>
void printCollection(const T& collection) {
    for(const auto& element : collection) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template<typename K, typename V> 
void printCollection(const std::map<K, V> &map) {
    for(const auto& element : map) {
        std::cout << element.first << " " << element.second << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6};
    std::map<int, std::string> map;
    double arr[20] = {0.2};
    std::list<char> list = {'a', 'z', 'b', 'y'}; 

    map[1] = "Hello, World!";
    map[2] = "Hello, CodeAcademy!";
    map[3] = "Hello, Everyone!";

    printCollection(vec);

    printCollection(map);

    printCollection(arr);

    printCollection(list);

    return 0;
}

