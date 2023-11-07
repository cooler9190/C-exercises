#include <iostream>
#include <vector>

using uI = unsigned int;

void biggestXor(std::vector<uI> vec) {
    uI maxXor = 0, a = 0, b = 0;
    
    for(int i = 0; i < vec.size(); ++i) {
        for(int j = i + 1; j < vec.size(); ++j) {
            uI max = vec[i] ^ vec[j];

            if(max > maxXor) {
                maxXor = max;
                a = vec[i];
                b = vec[j];
            }
        }
    }

    std::cout << "The biggest XOR is between elements "<< a << " and " << b << " which is " << maxXor <<std::endl;
}

int main() {    
    std::vector<uI> numbers = {25, 5, 3, 8, 10, 2};

    biggestXor(numbers);

    return 0;
}