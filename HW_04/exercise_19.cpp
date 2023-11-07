#include <iostream>

#define ldouble long double

// ldouble factorial(int n) {
//     if(n < 0) {
//         std::cout << "Factorial of a negative number does not exist!" << std::endl;
//         return 1;
//     }
//      ldouble x = 1;
//     for( int i = 1; i <= n; i++) {
//         x *= i;
//     }

//     return x;
// }

 int binomialCoefficient(int n, int k) {
    if(n < k) {
        int tmp = n;
        n = k;
        k = tmp;
    }
    if(n < 0) {
        std::cout << "Factorial of a negative number does not exist!" << std::endl;
        return 1;
    }
    ldouble factorialN = 1;
    for( int i = 1; i <= n; i++) {
        factorialN *= i;
    }

    ldouble factorialK = 1;
    for( int i = 1; i <= k; i++) {
        factorialK *= i;
    }

    ldouble factorialNK = 1;
    for( int i = 1; i <= (n - k); i++) {
        factorialNK *= i;
    }

    ldouble nominator = factorialN;
    ldouble denominator = factorialK * factorialNK;
    int coeff =  nominator / denominator;

    return coeff;
}

int main() {
    int n = 0, k = 0;

    std::cout << "Welcome to the C++ lottery!" << std::endl;
    std::cout << "Please enter the maximum number and the amount of numbers you can choose: ";
    std::cin >> n >> k;

    std::cout << "The number of cmobinations are: " << binomialCoefficient(n, k) << std::endl;
    std::cout << "Good luck :D" << std::endl;

    return 0;
}