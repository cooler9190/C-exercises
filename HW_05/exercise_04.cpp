#include <iostream>
#include <string>
#include <vector>


bool isSorted(std::vector<std::string> v) {
    std::vector<std::string> tmp(v);
    
    for(int i = 0; i < v.size(); ++i) {
        for(int j = i+1; j < v.size(); ++j) {
            if(v[i] > v[j]) {
                std::string tmps = v[j];
                v[j] = v[i];
                v[i] = tmps; 
            }
        }

    }

    if(tmp == v) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::vector<std::string> vec1 = {"apple", "avocado", "bannana", "beach", "fig"};

    if(isSorted(vec1)) {
        std::cout << "The vector is sorted." << std::endl;
    } else {
        std::cout << "The vector is not sorted." << std::endl;
    } 

    std::vector<std::string> vec2 = {"apple", "bannana", "avocado", "beach", "fig"};

    if(isSorted(vec2)) {
        std::cout << "The vector is sorted." << std::endl;
    } else {
        std::cout << "The vector is not sorted." << std::endl;
    }

    return 0;
}