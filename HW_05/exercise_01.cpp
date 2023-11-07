#include <iostream>
#include <vector>

void copyVector(std::vector<int> v1, std::vector<int> &v2) {
    for(int i = 0; i < v1.size(); i++) {
        v2.push_back(v1[i]);
    }
}

int main() {
    std::vector <int> prime = {2, 3, 5, 7, 11};
    std::vector <int> nonPrime = {0, 1, 4, 6, 8};

    copyVector(prime, nonPrime);

    for(int i = 0; i < prime.size(); i++) {
        std::cout << prime[i] << " ";
    }

    std::cout << std::endl;

    for(int i = 0; i < nonPrime.size(); i++) {
        std::cout << nonPrime[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}