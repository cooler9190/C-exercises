#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void printList(std::vector<signed int> &vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }    std::cout << std::endl;
}


int main() {
    std::vector<signed int> vec = {15, 1, 2, 3, 4, 5, -6, -7, -8, -9, -10};    
    std::vector<signed int> oddEvenVec = vec, posNegVec = vec;    
    
    std::sort(oddEvenVec.begin(), oddEvenVec.end(), [](const signed int &x, const signed int &y) {
        if(x % 2 == 0 && y % 2 == 0) {
            return x < y;
        } else if(x % 2 != 0 && y % 2 != 0) {
            return x > y;
        } else {
            return x % 2 == 0;
        }
    });   

    std::sort(posNegVec.begin(), posNegVec.end(), [](const signed int &x, const signed int &y) { return x > y; });    
    
    
    printList(oddEvenVec);    
    printList(posNegVec);    
    
    return 0;
}