#include <iostream>

const double (&maxSubArrSum(const double matr[][8], const int &size))[8] {
    double maxSum = 0, prevSum = 0;
    int maxSumIndex = 0;

    for(size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < 8; ++j) {
            prevSum += matr[i][j];
        }
        if(maxSum < prevSum) {
            maxSum = prevSum;
            maxSumIndex = i;
        }

        prevSum = 0;
    }

    return matr[maxSumIndex];
}

int main() {
    double matrix[][8] = {{0.1, 15.9, 30.0, 0.8, 12.3, 14.5, 17.7, 18.8},
                           {13.8, 18.9, 58.9, 12.3, 14.5, 17.7, 18.8, 89.9},
                           {0.01, 0.02, 0.03, 12.3, 14.5, 17.7, 18.8, 0.1}};
    

    std::cout << "The subarray with biggest sum is: ";
    for(double num : maxSubArrSum(matrix, 3)) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}