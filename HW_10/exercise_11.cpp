#include <iostream>
#include <vector>

using Criteria = bool (*)(unsigned int n);

int charBinary(const std::vector<unsigned char> &vec, Criteria crit) {
    int count = 0;
    for(char c : vec) {
        if(crit(c) == 1) {
            ++count;
        }
    }

    return count;
}

bool hasEqualOnesAndZeros(unsigned int n) {
    int oneCount = 0, zeroCount = 0;

    while(n > 0) {
        if((n & 1) == 0) {
            ++zeroCount;
        } else {
            ++oneCount;
        }
        n >>= 1;
    }

    if(oneCount == zeroCount) {
        return true;
    } else {
        return false;
    }

}

bool hasAlternatingBits(unsigned int n) {
    if(n > 1) {
        return ((n & (n >> 1))) == 0;
    } else {
        return false;
    }
}

int main() {
    std::vector<unsigned char> vector = {'C', 'o', 'd', 'e', 'A', 'c', 'a', 'd', 'e', 'm', 'y'};

    std::cout << "The vector has " << charBinary(vector, hasEqualOnesAndZeros) << " char/s with equal amount of ones and zeros." << std::endl;
    std::cout << "The vector has " << charBinary(vector, hasAlternatingBits) << " char/s with alternating bits." << std::endl;

    return 0;
}