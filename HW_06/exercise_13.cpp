#include <iostream>
#include <vector>

using uI = unsigned int;

void operations(std::vector<uI> vec) {
    uI andOp = 0, orOp = 0, xorOp = 0;

    andOp = vec[0] & vec[1];
    orOp = vec[0] | vec[1];
    xorOp = vec[0] ^ vec[1];
    
    for(int i = 2; i < vec.size(); ++i) {
        andOp &= vec[i];
        orOp |= vec[i];
        xorOp ^= vec[i];
    }

    std::cout << "Result of AND on whole set is: "<< andOp <<std::endl;
    std::cout << "Result of OR on whole set is: "<< orOp <<std::endl;
    std::cout << "Result of XOR on whole set is: "<< xorOp <<std::endl;
}

int main() {    
    std::vector<uI> numbers = {};
    uI number = 0;

    std::cout << "Please enter a set of positive integers: ";

    while(!std::cin.eof()) {
        std::cin >> number;

        numbers.push_back(number);
    }

    operations(numbers);

    return 0;
}